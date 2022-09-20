#pragma once

#include "langcc_util.hpp"

#include "common__data_gen.hpp"

using namespace common;

#define GRAPH_P template<typename Vertex, typename Label>

namespace common::Graph {
    GRAPH_P struct _T;
}
GRAPH_P using Graph_T = rc_ptr<common::Graph::_T<Vertex, Label>>;

#define GRAPH_A Graph_T<Vertex, Label>

namespace common::Graph {
    struct _T_inner {
        vector<vector<Int>> EL_;
        vector<vector<vector<Int>>> EV_;
        vector<unordered_map<Int, Int>> ELI_;
        vector<unordered_map<Int, unordered_set<Int>>> ES_;

        inline Int add_vertex() {
            Int ret = EL_.size();
            EL_.push_back(vector<Int>());
            EV_.push_back(vector<vector<Int>>());
            ELI_.push_back(unordered_map<Int, Int>());
            ES_.push_back(unordered_map<Int, unordered_set<Int>>());
            return ret;
        }

        inline bool add_edge(Int i, Int l, Int j) {
            bool ret = false;
            if (ELI_[i].find(l) == ELI_[i].end()) {
                ELI_[i].insert(make_pair(l, EL_[i].size()));
                EL_[i].push_back(l);
                EV_[i].push_back(vector<Int>());
            }
            if (ES_[i].find(l) == ES_[i].end()) {
                ES_[i].insert(make_pair(l, unordered_set<Int>()));
            }
            if (ES_[i][l].find(j) == ES_[i][l].end()) {
                ret = true;
                AT(ELI_[i][l] < EV_[i].size());
                EV_[i][ELI_[i][l]].push_back(j);
            }
            ES_[i][l].insert(j);
            return ret;
        }
    };

    GRAPH_P struct _T {
        VecUniq_T<Vertex> V_;
        VecUniq_T<Label> L_;
        _T_inner fwd_;
        _T_inner rev_;
        Int num_edges_;
    };

    GRAPH_P GRAPH_A empty() {
        auto G = make_rc<Graph::_T<Vertex, Label>>();
        G->V_ = make_rc<VecUniq<Vertex>>();
        G->L_ = make_rc<VecUniq<Label>>();
        G->num_edges_ = 0;
        return G;
    }

    GRAPH_P Int N(const GRAPH_A& G) {
        return G->V_->length();
    }

    GRAPH_P Int M(const GRAPH_A& G) {
        return G->num_edges_;
    }

    GRAPH_P Int add_vertex(GRAPH_A& G, const Vertex& v) {
        auto ret = G->V_->insert_strict(v);
        auto ret1 = G->fwd_.add_vertex();
        auto ret2 = G->rev_.add_vertex();
        AT(ret == ret1);
        AT(ret == ret2);
        return ret;
    }

    GRAPH_P Vertex vertex_by_ind(GRAPH_A& G, Int i) {
        check_range(i, N(G));
        return G->V_->at_index(i);
    }

    GRAPH_P GRAPH_A vertex_only_copy(const GRAPH_A& G) {
        auto ret = Graph::empty<Vertex, Label>();
        for (Int i = 0; i < N(G); i++) {
            ret->add_vertex(G->V_->at(i));
        }
        return ret;
    }

    GRAPH_P bool add_edge(GRAPH_A& G, Vertex v_src, Label label, Vertex v_dst) {
        auto lm = G->L_->index_of_maybe(label);
        if (lm.is_none()) {
            G->L_->insert_strict(label);
        }

        auto i = G->V_->index_of_maybe(v_src).as_some();
        auto j = G->V_->index_of_maybe(v_dst).as_some();
        auto l = G->L_->index_of_maybe(label).as_some();

        auto ret = G->fwd_.add_edge(i, l, j);
        auto ret1 = G->rev_.add_edge(j, l, i);
        AT(ret == ret1);
        if (ret) {
            ++G->num_edges_;
        }
        return ret;
    }
}
