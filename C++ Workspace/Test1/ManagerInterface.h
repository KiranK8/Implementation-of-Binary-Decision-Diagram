//
// Created by kiran on 14-12-2021.
//

#ifndef TEST1_MANAGERINTERFACE_H
#define TEST1_MANAGERINTERFACE_H

#endif //TEST1_MANAGERINTERFACE_H

#include <iostream>
using namespace std;

typedef int BDD_ID;
struct table{
    string node;
    BDD_ID iID, iHigh, iLow, iTopVar;
}BDD_table[5];

int GL_Top;

BDD_ID createVar(const std::string &label);

const BDD_ID &True();

const BDD_ID &False();

bool isConstant(const BDD_ID f);

bool isVariable(const BDD_ID x);

BDD_ID topVar(const BDD_ID f);

BDD_ID ite(const BDD_ID i, const BDD_ID t, const BDD_ID e);

BDD_ID coFactorTrue(const BDD_ID f, BDD_ID x);

BDD_ID coFactorFalse(const BDD_ID f, BDD_ID x);

BDD_ID neg(const BDD_ID a);

BDD_ID and2(const BDD_ID a, const BDD_ID b);

std::string getTopVarName(const BDD_ID &root);

void findNodes(const BDD_ID &root, std::set<BDD_ID>&nodes_of_root);

void findVars(const BDD_ID &root, std::set<BDD_ID>&vars_of_root);

size_t uniqueTableSize();
