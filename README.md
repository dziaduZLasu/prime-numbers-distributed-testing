prime-numbers-distributed-testing
=================================

Finding prime numbers 

Find prime numbers in given range where each digt is less eq then following digit and sum of digits is also prime number.
Using  Miller Rabin test in MPI CPP distributed env

 ./make
 cd dist/Debug/GNU-Linux-x86
 mpirun -np N lp_mpi

this runs program WITH N MPI nodes
