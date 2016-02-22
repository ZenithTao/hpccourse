#!/bin/sh
#PBS -N HelloWorld
# nodes is the number of computers to use. Adjust as needed. MAX is 8. Leave ppn alone. Adjust walltime to max time to allow your binary to run.
#PBS -l nodes=4:ppn=32,mem=2GB,walltime=00:00:15
#PBS -q batch
# If you want email notifications, remove the extra # in front of the #PBS -M and #PBS -m lines
##PBS -M <YOUR EMAIL ADDRESS HERE>
##PBS -m abe
# Set the correct PATH and env for the MPI implelementation
#/usr/lib64/{openmpi,mpich,mvapich2}/bin
MPIRUN='/usr/lib64/openmpi/bin/mpirun -mca plm_rsh_agent rsa --map-by node --display-allocation -mca orte_base_help_aggregate 0 -mca btl ^openib'
WORK_HOME=/home/ashish/MPI/HelloWorld
cd $WORK_HOME
$MPIRUN -np 8 --machinefile $PBS_NODEFILE ./lab

