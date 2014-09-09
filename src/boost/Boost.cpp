// M. Reid - Boost.cpp - Test of boost mpi interface

#include <iostream>

// The boost headers
#include "boost/mpi.hpp"

int main(int argc, char* argv[])
{
    // Allows you to query the MPI environment
    boost::mpi::environment env(argc, argv);
    std::string processor_name(env.processor_name());

    // permits communication and synchronization among a set of processes
    boost::mpi::communicator world;
    unsigned int rank(world.rank()), numprocessors(world.size());

    if (rank == 0) {
        std::cout << "Processor name: " << processor_name << "\n";
    	std::cout << "Master (" << rank << "/" << numprocessors << ")\n";
    } else {
    	std::cout << "Slave  (" << rank << "/" << numprocessors << ")\n";
    }
    return 0;
}
