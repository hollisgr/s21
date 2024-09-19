#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *brickgame_test[] = {test_tetris(), NULL};

  for (int i = 0; brickgame_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(brickgame_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed;
}
