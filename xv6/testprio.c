#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid = getpid();

  printf(1, "--- Starting Priority Tests ---\n");

  // Test 1: Valid inputs (Setting own priority to 2)
  printf(1, "Test 1: Setting self (PID %d) to priority 2... ", pid);
  if(setpriority(pid, 2) == 0){
    printf(1, "SUCCESS\n");
  } else {
    printf(1, "FAILED\n");
  }

  // Test 2: Invalid PID
  printf(1, "Test 2: Setting non-existent PID 999 to priority 0... ");
  if(setpriority(999, 0) == -1){
    printf(1, "SUCCESS (Correctly rejected)\n");
  } else {
    printf(1, "FAILED (Accepted invalid PID)\n");
  }

  // Test 3: Invalid Priority Value (e.g., 5)
  printf(1, "Test 3: Setting PID %d to invalid priority 5... ", pid);
  if(setpriority(pid, 5) == -1){
    printf(1, "SUCCESS (Correctly rejected)\n");
  } else {
    printf(1, "FAILED (Accepted invalid priority)\n");
  }

  printf(1, "--- Tests Completed ---\n");
  exit();
}