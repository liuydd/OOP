#include "graph.h"
#include "operation_minus.h"
#include "operation_plus.h"

Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    // wait to fill, 使用nodes_.insert()新建一个占位符
    Node *newPlaceholder = new PlaceholderNode(node_name);
    nodes_.insert(node_name,newPlaceholder);
}

void Graph::InsertConstant(const string &node_name, float value) {
    // wait to fill, 使用nodes_.insert()新建一个常量
    Node *newConstant = new ConstantNode(node_name,value);
    nodes_.insert(node_name,newConstant);
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    // wait to fill, 根据operation_type的名字调用相应的运算符节点构造函数
    Node *newoperation=nullptr;
    if(operation_type=="+"){
        newoperation=new OperationPlus(node_name,nodes_[input1],nodes_[input2]);
    }
    else if(operation_type=="-"){
        newoperation=new OperationMinus(node_name,nodes_[input1],nodes_[input2]);
    }
    nodes_.insert(node_name,newoperation);
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {

    // wait to fill, 调用相应的placeholder的set_val函数
    for(int i=0;i<argument_num;i++){
        float val=argument_value_list_[i];
        dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]])->set_val(val);
    }
    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;   
}

Graph::~Graph() {
    
}


