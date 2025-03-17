//
// Written by Carolina P. Nogueira 2016
// Refactored by Deutschmann 27.09.2021
//

#pragma once

#include "BenchParser.hpp"
#include "../ManagerInterface.h"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>


/**
 * \class CircuitToBDD
 * 
 * \brief Class to convert circuits nodes into BDD nodes
 *
 *  Circuit nodes are generated by the class bench_circuit_manager.
 *
 * \authors {Carolina Nogueira, Lucas Deutschmann}
 * 
 */
class CircuitToBDD {

public:

    explicit CircuitToBDD(shared_ptr<ClassProject::ManagerInterface> BDD_manager_p);
    ~CircuitToBDD();

    /**
     * \brief Generates a BDD from the circuit nodes provided
     * \param Topologically sorted list containing the circuit nodes
     * \return none
     *
     *  Generates the calls to the BDD package in order to
     *   generate the BDD equivalent to the provided circuit.
     */
    void GenerateBDD(const std::list<circuit_node_t> &circuit, std::string benchmark_file);


    /**
     * \brief Print the generated BDD in text and dot format
     * \param The set of output labels to print a BDD for
     * \return none
     */
    void PrintBDD(const std::set<label_t> &output_labels);

private:

    boost::unordered_map<unique_ID_t, ClassProject::BDD_ID> node_to_bdd_id; ///< Mapping from circuit node's unique ID to its BDD ID
    std::unordered_map<label_t, ClassProject::BDD_ID> label_to_bdd_id; ///< Mapping from node's label to its BDD ID

    shared_ptr<ClassProject::ManagerInterface> bdd_manager{};
    std::string result_dir; ///< Directory where the results are stored

    std::set<ClassProject::BDD_ID> output_nodes;
    std::set<ClassProject::BDD_ID> output_vars;


    /**
     * \brief Returns the BDD_ID of the given circuit ID
     * \param circuit_node is unique_ID_t
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID findBddId(unique_ID_t circuit_node);

    /**
     * \brief Generates the BDD node equivalent to a variable with label "label".
     * \param label is label_t
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID InputGate(const label_t &label);

    /**
     * \brief Generates the BDD node equivalent to the NOT gate.
     * \param node is set_of_circuit_t containing the circuit ID of the gate to be inverted.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID NotGate(const set_of_circuit_t &node);

    /**
     * \brief Generates the BDD node equivalent to the AND gate.
     * \param node is set_of_circuit_t containing the circuit IDs of the gates to be used as input.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID AndGate(set_of_circuit_t inputNodes);

    /**
     * \brief Generates the BDD node equivalent to the OR gate.
     * \param node is set_of_circuit_t containing the circuit IDs of the gates to be used as input.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID OrGate(set_of_circuit_t inputNodes);

    /**
     * \brief Generates the BDD node equivalent to the NAND gate.
     * \param node is set_of_circuit_t containing the circuit IDs of the gates to be used as input.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID NandGate(set_of_circuit_t inputNodes);

    /**
     * \brief Generates the BDD node equivalent to the NOR gate.
     * \param node is set_of_circuit_t containing the circuit IDs of the gates to be used as input.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID NorGate(set_of_circuit_t inputNodes);

    /**
     * \brief Generates the BDD node equivalent to the XOR gate.
     * \param node is set_of_circuit_t containing the circuit IDs of the gates to be used as input.
     * \return ClassProject::BDD_ID
     *
     */
    ClassProject::BDD_ID XorGate(set_of_circuit_t inputNodes);

    void dumpBddText(std::ostream &out);

    void dumpBddDot(std::ostream &out);
};   
