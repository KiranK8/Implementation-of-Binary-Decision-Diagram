# VDS Class Project (ROBDD Implementation)

## Overview
This project is part of the **Verification of Digital Systems** course, focusing on the implementation of a **Reduced Ordered Binary Decision Diagram (ROBDD)** package in **C++**. The goal is to develop a minimal BDD package with fundamental manipulation methods, following the **Test-Driven Development (TDD)** paradigm and utilizing **Continuous Integration (CI)** with GitHub Actions.

---

## Project Structure
The project is divided into three parts:

### **Part 1: Basic BDD Functionality with TDD**
- Implement the core BDD operations following TDD best practices.
- Set up and maintain a **GitHub repository** for version control.
- Use **CMake** as the build system.
- Verify implementation using **Google Test (GTest)**.
- Establish a **CI pipeline with GitHub Actions**.
- Generate documentation using **Doxygen**.

### **Part 2: Performance Optimization**
- Identify and optimize performance bottlenecks in the implementation.
- Utilize benchmarks to evaluate efficiency.
- Ensure optimizations remain within a reasonable memory footprint.

### **Part 3: State Reachability Analysis**
- Extend the implementation to check whether a specific state is reachable given an initial state.
- Implement algorithms for reachability analysis.
- Validate correctness using test cases provided by the instructors.

---

## Getting Started
### **1. Clone the Repository**
```sh
git clone https://github.com/yourusername/VDSProject_GroupX.git
cd VDSProject_GroupX
```

### **2. Build the Project using CMake**
```sh
mkdir build
cd build
cmake ..
make
```

### **3. Run Tests**
```sh
./test/VDSCP_tests
```

---

## Implementation Details
### **Data Structures**
The project involves implementing the **Manager class**, which inherits functions from **ManagerInterface**. The core data structure is a table that stores BDD nodes with attributes:
- **BDD ID**
- **High and Low branches**
- **Top variable**

### **Key Functions Implemented**
- **createVar(label)** - Creates a new variable and returns its ID.
- **isConstant(BDD ID f)** - Checks if a node is a leaf (True/False).
- **isVariable(BDD ID x)** - Determines if a node represents a variable.
- **topVar(BDD ID f)** - Retrieves the top variable ID of a given node.
- **ite(i, t, e)** - Implements the If-Then-Else algorithm.
- **coFactorTrue(f, x)** / **coFactorFalse(f, x)** - Computes positive and negative co-factors.
- **neg(f)**, **and2(f, g)**, **or2(f, g)** - Logical operations on BDDs.
- **findNodes(root)**, **findVars(root)** - Retrieves reachable nodes/variables.
- **uniqueTableSize()** - Returns the number of nodes in the unique table.

---

## Development Methodologies
### **1. Test-Driven Development (TDD)**
- Every new feature begins with writing test cases.
- Implementation is iteratively improved based on test results.
- Testing framework: **Google Test (GTest)**.

### **2. Code Documentation with Doxygen**
- Generates structured documentation for API functions.
- Ensures maintainability and usability of the codebase.

---

## Contributors
- Kiran Kannur
