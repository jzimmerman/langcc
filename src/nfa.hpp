#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"

#include "graph.hpp"

namespace langcc {

namespace NFA {
template <typename Vertex, typename Label, typename Acc> struct _T {
  Graph_T<Vertex, Label> G_;
  Option_T<Int> start_;
  Vec_T<Set_T<Acc>> acc_;
  bool finalized_{};
};
} // namespace NFA

template <typename Vertex, typename Label, typename Acc>
using NFA_T = rc_ptr<NFA::_T<Vertex, Label, Acc>>;

template <typename Vertex, typename Label, typename Acc>
inline void pr(std::ostream &os, FmtFlags /*flags*/,
               const NFA_T<Vertex, Label, Acc> &N) {
  std::vector<std::tuple<Int, Align>> aligns = {
      {2, Align::RIGHT}, {2, Align::RIGHT}, {2, Align::LEFT}};

  auto td = PrintTable::make(aligns);

  for (Int i = 0; i < Graph::N(N->G_); i++) {
    Vertex vi = N->G_->V_->operator[](i);
    td->push(fmt_str("{}:", i));
    td->push(fmt_str("{}", vi));
    if (N->acc_->operator[](i)->length() == 0) {
      td->push_blank_item();
    } else {
      std::string s;
      bool fresh = true;
      for (const auto &acc : *N->acc_->operator[](i)) {
        if (!fresh) {
          s += ", ";
        }
        fresh = false;
        s += fmt_str("{}", acc);
      }
      td->push(s);
    }

    if (N->G_->fwd_.EL_.at(i).size() > 0) {
      td->push_blank_line();
    }

    for (Int li = 0; li < N->G_->fwd_.EL_.at(i).size(); li++) {
      auto lbl_ind = N->G_->fwd_.EL_.at(i).at(li);
      const auto &nbr_inds = N->G_->fwd_.EV_.at(i).at(li);
      auto lbl = N->G_->L_->operator[](lbl_ind);

      td->push_blank_item();
      td->push(fmt_str("{}", lbl));
      std::string rhs = "--> ";
      bool fresh = true;
      for (const auto &w : nbr_inds) {
        if (!fresh) {
          rhs += ", ";
        }
        fresh = false;
        rhs += fmt_str("{}", w);
      }
      td->push(rhs);
    }

    if (i + 1 < Graph::N(N->G_)) {
      td->push_blank_line();
    }
  }

  fmt(os, "{}", td);
}

namespace NFA {
template <typename Vertex, typename Label, typename Acc>
NFA_T<Vertex, Label, Acc> empty() {
  auto ret = make_rc<NFA::_T<Vertex, Label, Acc>>();
  ret->G_ = Graph::empty<Vertex, Label>();
  ret->start_ = None<Int>();
  ret->acc_ = make_rc<Vec<Set_T<Acc>>>();
  ret->finalized_ = false;
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
Int add_vertex(NFA_T<Vertex, Label, Acc> &N, Vertex v) {
  auto ret = Graph::add_vertex(N->G_, v);
  N->acc_->push(make_rc<Set<Acc>>());
  AT(Graph::N(N->G_) == N->acc_->length());
  AT(ret == N->acc_->length() - 1);
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
std::pair<Int, bool> ensure_vertex(NFA_T<Vertex, Label, Acc> &N, Vertex v) {
  auto ret = N->G_->V_->index_of_maybe(v);
  if (ret.is_some()) {
    return std::make_pair(ret.as_some(), false);
  }
  return std::make_pair(NFA::add_vertex(N, v), true);
}

template <typename Vertex, typename Label, typename Acc>
Vertex gen_vertex(NFA_T<Vertex, Label, Acc> &N) {
  auto ret = Graph::N(N->G_);
  Graph::add_vertex(N->G_, ret);
  N->acc_->push(make_rc<Set<Acc>>());
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
void add_action(NFA_T<Vertex, Label, Acc> &N, Vertex v, Acc acc) {
  auto i = N->G_->V_->index_of_maybe(v).as_some();
  N->acc_->operator[](i)->insert(acc);
}

template <typename Vertex, typename Label, typename Acc>
Vertex gen_vertex_acc(NFA_T<Vertex, Label, Acc> &N, Acc acc) {
  auto ret = Graph::N(N->G_);
  Graph::add_vertex(N->G_, ret);
  auto acc_s = make_rc<Set<Acc>>();
  acc_s->insert(acc);
  N->acc_->push(acc_s);
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
Vertex gen_vertex_start(NFA_T<Vertex, Label, Acc> &N) {
  auto ret = gen_vertex(N);
  AT(N->start_.is_none());
  N->start_ = Some<Int>(N->G_->V_->index_of_maybe(ret).as_some());
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
void add_edge(NFA_T<Vertex, Label, Acc> &N, Vertex v_src, Label label,
              Vertex v_dst) {
  Graph::add_edge(N->G_, v_src, label, v_dst);
}

template <typename Vertex, typename Label, typename Acc>
VecUniq_T<Label> all_labels(NFA_T<Vertex, Label, Acc> &N) {
  return N->G_->L_;
}

template <typename Vertex, typename Label, typename Acc>
VecUniq_T<Vertex> all_vertices(NFA_T<Vertex, Label, Acc> &N) {
  return N->G_->V_;
}

template <typename Vertex, typename Label, typename Acc>
Map_T<Label, Vec_T<Vertex>> outgoing_edges(NFA_T<Vertex, Label, Acc> &N,
                                           Vertex v) {
  auto ret = make_rc<Map<Label, Vec_T<Vertex>>>();
  auto vi = N->G_->V_->index_of_maybe(v).as_some();
  for (Int li = 0; li < N->G_->fwd_.EL_.at(vi).size(); li++) {
    auto lbl_ind = N->G_->fwd_.EL_.at(vi).at(li);
    const auto &nbr_inds = N->G_->fwd_.EV_.at(vi).at(li);
    auto lbl = N->G_->L_->operator[](lbl_ind);
    auto nbrs = make_rc<Vec<Vertex>>();
    for (const auto &nbr_ind : nbr_inds) {
      nbrs->push_back(N->G_->V_->operator[](nbr_ind));
    }
    ret->insert(lbl, nbrs);
  }
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
Map_T<Label, Vec_T<Vertex>> incoming_edges(NFA_T<Vertex, Label, Acc> &N,
                                           Vertex v) {
  auto ret = make_rc<Map<Label, Vec_T<Vertex>>>();
  auto vi = N->G_->V_->index_of_maybe(v).as_some();
  for (Int li = 0; li < N->G_->rev_.EL_.at(vi).size(); li++) {
    auto lbl_ind = N->G_->rev_.EL_.at(vi).at(li);
    const auto &nbr_inds = N->G_->rev_.EV_.at(vi).at(li);
    auto lbl = N->G_->L_->operator[](lbl_ind);
    auto nbrs = make_rc<Vec<Vertex>>();
    for (const auto &nbr_ind : nbr_inds) {
      nbrs->push_back(N->G_->V_->operator[](nbr_ind));
    }
    ret->insert(lbl, nbrs);
  }
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
Set_T<Int> eps_closure(NFA_T<Vertex, Label, Acc> &N, const Set_T<Int> &vs) {
  auto ret = make_rc<Set<Int>>();
  Vec<Int> Q;
  for (const auto &v : *vs) {
    ret->insert(v);
    Q.push_back(v);
  }
  while (!Q.empty()) {
    auto v = Q.pop_front_val();

    for (Int li = 0; li < N->G_->fwd_.EL_.at(v).size(); li++) {
      auto lbl_ind = N->G_->fwd_.EL_.at(v).at(li);
      const auto &nbr_inds = N->G_->fwd_.EV_.at(v).at(li);
      auto lbl = N->G_->L_->operator[](lbl_ind);

      if (!lbl->is_Eps()) {
        continue;
      }

      for (const auto &nbr : nbr_inds) {
        if (!ret->contains(nbr)) {
          ret->insert(nbr);
          Q.push_back(nbr);
        }
      }
    }
  }
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
Set_T<Vertex> vertex_set_lookup(NFA_T<Vertex, Label, Acc> &N, Set_T<Int> s) {
  auto ret = make_rc<Set<Vertex>>();
  for (const auto &i : *s) {
    ret->insert(N->G_->V_->operator[](i));
  }
  return ret;
}

template <typename Vertex, typename Label, typename Acc>
NFA_T<Set_T<Vertex>, Label, Acc>
nfa_subset_constr(NFA_T<Vertex, Label, Acc> &N) {
  auto D = NFA::empty<Set_T<Int>, Label, Acc>();

  Map<Set_T<Int>, std::pair<Label, Set_T<Int>>> reach_rev;

  Vec<Set_T<Int>> Q;

  auto N_start = N->start_.as_some();
  auto D_start = NFA::eps_closure(N, Set<Int>::singleton(N_start));

  {
    auto ns_i = NFA::add_vertex(D, D_start);
    D->start_ = Some<Int>(ns_i);

    auto ns_acc = make_rc<Set<Acc>>();
    for (const auto &n : *D_start) {
      auto n_acc = N->acc_->operator[](n);
      ns_acc = ns_acc->with_union(n_acc);
    }
    D->acc_->operator[](ns_i) = ns_acc;
    Q.push_back(D_start);
  }

  while (!Q.empty()) {
    auto vs = Q.pop_front_val();

    Set<Label> all_labels;

    for (const auto &v : *vs) {
      for (Int li = 0; li < N->G_->fwd_.EL_.at(v).size(); li++) {
        auto lbl_ind = N->G_->fwd_.EL_.at(v).at(li);
        auto lbl = N->G_->L_->operator[](lbl_ind);

        if (lbl->is_Eps()) {
          continue;
        }

        all_labels.insert(lbl);
      }
    }

    for (const auto &lbl_iter : all_labels) {
      auto ns = make_rc<Set<Int>>();

      for (const auto &v : *vs) {
        for (Int li = 0; li < N->G_->fwd_.EL_.at(v).size(); li++) {
          auto lbl_ind = N->G_->fwd_.EL_.at(v).at(li);
          const auto &nbr_inds = N->G_->fwd_.EV_.at(v).at(li);
          auto lbl = N->G_->L_->operator[](lbl_ind);

          if (val_hash(lbl) != val_hash(lbl_iter)) {
            continue;
          }

          for (const auto &nbr : nbr_inds) {
            ns->insert(nbr);
          }
        }
      }

      AT(ns->length() > 0);

      ns = NFA::eps_closure(N, ns);

      if (D->G_->V_->index_of_maybe(ns).is_none()) {
        auto nsv = NFA::vertex_set_lookup(N, ns);
        auto ns_i = NFA::add_vertex(D, ns);
        reach_rev.insert(ns, std::make_pair(lbl_iter, vs));
        auto ns_acc = make_rc<Set<Acc>>();
        for (const auto &n : *ns) {
          auto n_acc = N->acc_->operator[](n);
          ns_acc = ns_acc->with_union(n_acc);
        }
        D->acc_->operator[](ns_i) = ns_acc;
        Q.push_back(ns);
      }

      NFA::add_edge(D, vs, lbl_iter, ns);
    }
  }

  D->finalized_ = true;

  auto Dv = NFA::empty<Set_T<Vertex>, Label, Acc>();

  Dv->start_ = D->start_;
  Dv->acc_ = D->acc_;
  for (const auto &s : *D->G_->V_) {
    auto sv = NFA::vertex_set_lookup(N, s);
    AT(Dv->G_->V_->index_of_maybe(sv).is_none());
    Dv->G_->V_->insert(sv);
  }
  Dv->G_->L_ = D->G_->L_;
  Dv->G_->fwd_ = D->G_->fwd_;
  Dv->G_->rev_ = D->G_->rev_;
  Dv->G_->num_edges_ = D->G_->num_edges_;

  Dv->finalized_ = true;

  return Dv;
}

template <typename Vertex, typename Label, typename Acc>
bool has_conflicts(NFA_T<Vertex, Label, Acc> &D) {
  for (const auto &v : *D->G_->V_) {
    auto vi = D->G_->V_->index_of_maybe(v).as_some();
    auto acc_i = D->acc_->operator[](vi);
    if (acc_set_has_conflicts(acc_i)) {
      return true;
    }
  }
  return false;
}

template <typename Vertex, typename Label, typename Acc>
rc_ptr<NFA::_T<Int, Label, Acc>> vertex_stripped(NFA_T<Vertex, Label, Acc> &N) {
  auto ret = NFA::empty<Int, Label, Acc>();

  for (const auto &v : *N->G_->V_) {
    auto vi = NFA::gen_vertex(ret);
    AT(vi == N->G_->V_->index_of_maybe(v).as_some());
  }

  ret->start_ = N->start_;
  for (Int i = 0; i < ret->acc_->length(); i++) {
    ret->acc_->operator[](i) = N->acc_->operator[](i);
  }

  for (Int i = 0; i < Graph::N(N->G_); i++) {
    for (Int li = 0; li < N->G_->fwd_.EL_.at(i).size(); li++) {
      auto lbl_ind = N->G_->fwd_.EL_.at(i).at(li);
      const auto &nbr_inds = N->G_->fwd_.EV_.at(i).at(li);
      auto lbl = N->G_->L_->operator[](lbl_ind);
      for (const auto &nbr : nbr_inds) {
        NFA::add_edge(ret, i, lbl, nbr);
      }
    }
  }

  return ret;
}

template <typename Vertex, typename Label>
NFA_T<Vertex, Label, Unit> dfa_negated(NFA_T<Vertex, Label, Unit> &D,
                                       VecUniq_T<Label> all_labels) {

  auto ret = NFA::empty<Vertex, Label, Unit>();

  for (const auto &v : *D->G_->V_) {
    auto vi = NFA::gen_vertex(ret);
    AT(vi == D->G_->V_->index_of_maybe(v).as_some());
  }

  ret->start_ = D->start_;
  for (Int i = 0; i < ret->acc_->length(); i++) {
    auto acc_s = make_rc<Set<Unit>>();
    if (D->acc_->operator[](i)->length() == 1) {
      // pass
    } else if (D->acc_->operator[](i)->length() == 0) {
      acc_s->insert(Unit{});
    } else {
      AX();
    }
    ret->acc_->operator[](i) = acc_s;
  }

  auto sink = NFA::gen_vertex_acc(ret, Unit{});
  for (const auto &lbl : *all_labels) {
    NFA::add_edge(ret, sink, lbl, sink);
  }

  for (Int i = 0; i < Graph::N(D->G_); i++) {
    Set<Label> labels_rem;
    for (const auto &lbl : *all_labels) {
      labels_rem.insert_strict(lbl);
    }

    for (Int li = 0; li < D->G_->fwd_.EL_.at(i).size(); li++) {
      auto lbl_ind = D->G_->fwd_.EL_.at(i).at(li);
      const auto &nbr_inds = D->G_->fwd_.EV_.at(i).at(li);
      auto lbl = D->G_->L_->operator[](lbl_ind);
      AT(labels_rem.contains(lbl));
      labels_rem.remove(lbl);
      for (const auto &nbr : nbr_inds) {
        NFA::add_edge(ret, i, lbl, nbr);
      }
    }

    for (const auto &lbl : labels_rem) {
      NFA::add_edge(ret, i, lbl, sink);
    }
  }

  return ret;
}

template <typename Vertex, typename Label>
NFA_T<std::pair<Vertex, Vertex>, Label, Unit>
dfa_product(NFA_T<Vertex, Label, Unit> &Da, NFA_T<Vertex, Label, Unit> &Db) {

  auto ret = NFA::empty<std::pair<Vertex, Vertex>, Label, Unit>();

  for (const auto &v : *Da->G_->V_) {
    for (const auto &w : *Db->G_->V_) {
      auto vw = std::make_pair(v, w);
      auto vi = Da->G_->V_->index_of_maybe(v).as_some();
      auto wi = Db->G_->V_->index_of_maybe(w).as_some();
      Int vw_i = NFA::add_vertex(ret, vw);
      if (vi == Da->start_.as_some() && wi == Db->start_.as_some()) {
        ret->start_ = Some<Int>(vw_i);
      }
      if (Da->acc_->operator[](vi)->length() > 0 &&
          Db->acc_->operator[](wi)->length() > 0) {
        ret->acc_->operator[](vw_i)->insert(Unit{});
      }
    }
  }

  for (const auto &v : *Da->G_->V_) {
    auto vi = Da->G_->V_->index_of_maybe(v).as_some();

    for (Int v_li = 0; v_li < Da->G_->fwd_.EL_.at(vi).size(); v_li++) {
      auto v_lbl_ind = Da->G_->fwd_.EL_.at(vi).at(v_li);
      const auto &v_nbr_inds = Da->G_->fwd_.EV_.at(vi).at(v_li);
      auto v_lbl = Da->G_->L_->operator[](v_lbl_ind);

      for (const auto &w : *Db->G_->V_) {
        auto vw = std::make_pair(v, w);
        auto wi = Db->G_->V_->index_of_maybe(w).as_some();

        for (Int w_li = 0; w_li < Db->G_->fwd_.EL_.at(wi).size(); w_li++) {
          auto w_lbl_ind = Db->G_->fwd_.EL_.at(wi).at(w_li);
          const auto &w_nbr_inds = Db->G_->fwd_.EV_.at(wi).at(w_li);
          auto w_lbl = Db->G_->L_->operator[](w_lbl_ind);

          if (val_hash(v_lbl) != val_hash(w_lbl)) {
            continue;
          }

          for (const auto &v_nbr : v_nbr_inds) {
            for (const auto &w_nbr : w_nbr_inds) {
              auto vw_nbr = std::make_pair(v_nbr, w_nbr);
              NFA::add_edge(ret, vw, v_lbl, vw_nbr);
            }
          }
        }
      }
    }
  }

  return ret;
}

template <typename SrcVertex, typename Vertex, typename Label, typename Acc>
void splice_in(NFA_T<Vertex, Label, Acc> &dst,
               NFA_T<SrcVertex, Label, Unit> &src, Vertex w0, Vertex w1,
               Label eps) {

  Vec<Int> vm;
  for (Int vi = 0; vi < src->G_->V_->length(); vi++) {
    auto vi_dst = NFA::gen_vertex(dst);
    vm.push(vi_dst);
  }

  for (Int vi = 0; vi < src->G_->V_->length(); vi++) {
    if (vi == src->start_.as_some()) {
      NFA::add_edge(dst, w0, eps, vm[vi]);
    }

    if (src->acc_->operator[](vi)->length() == 1) {
      NFA::add_edge(dst, vm[vi], eps, w1);
    } else if (src->acc_->operator[](vi)->length() == 0) {
      // pass
    } else {
      AX();
    }

    for (Int li = 0; li < src->G_->fwd_.EL_.at(vi).size(); li++) {
      auto lbl_ind = src->G_->fwd_.EL_.at(vi).at(li);
      const auto &nbr_inds = src->G_->fwd_.EV_.at(vi).at(li);
      auto lbl = src->G_->L_->operator[](lbl_ind);
      for (const auto &nbr : nbr_inds) {
        NFA::add_edge(dst, vm[vi], lbl, vm[nbr]);
      }
    }
  }
}
} // namespace NFA

} // namespace langcc
