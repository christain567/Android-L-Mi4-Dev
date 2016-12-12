#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mode;
    // int operation;
    // int result;
    int operation_id;
    int cmd_id;
} struct_test;


typedef enum {
    TEST_ONE,
    TEST_TWO,
    TEST_THREE,
    TEST_FOUR,
    TEST_FIVE,
    TEST_SIX,
    TEST_SEVEN,
}enum_zl;


int main()
{

    struct_test *test = NULL;
    void *test1 = NULL;
    enum_zl  zl[10];

    int cmd_id = 8;
    int operation_id = 7;

    test = (struct_test *) malloc(sizeof(struct_test));
    printf("%s the sizeof struct_test is: %d.\n", __func__, sizeof(struct_test));
    if(NULL == test) {
    	printf("%s MALLOC FAILED !\n",__func__ );
    	return -1;
    }

    test->mode = 1;
    // test->operation = 2;
    // test->result = 3;
    test->operation_id = 0;
    test->cmd_id = 0;

    test1 = (void *) test;
    //strcpy((int *)(test1 + sizeof(struct_test) -8), &operation_id);
    //strcpy((int *)(test1 + sizeof(struct_test) -4), &cmd_id);
    *(int *)(test1 + sizeof(struct_test) -8) = operation_id;
    *(int *)(test1 + sizeof(struct_test) -4) =cmd_id;

    printf("%s operation_id=%d, cmd_id=%d.\n",__func__, test->operation_id, test->cmd_id);
    printf("%s operation_id1=%d, cmd_id1=%d.\n",__func__, *(int *)(test1 + sizeof(struct_test) -8), *(int *)(test1 + sizeof(struct_test) -4));

    printf("%s enum_zl=%d, zl=%d.\n",__func__, sizeof(enum_zl), sizeof(zl));
    if(NULL != test) {
        free(test);
        test = NULL;
    }

	return 0;
}
