#include "lox__gen.hpp"

using namespace langcc;

using namespace lang::lox;
using namespace lang::lox::Node;

using Node_S = Node::_T*;
using Block_S = Node::Block::_T*;
using Prog_S = Node::Prog::_T*;
using Stmt_S = Node::Stmt::_T*;
using Expr_S = Node::Expr::_T*;

bool lox_proc_file(string filename);
