#ifndef v1_container_TEST
#define v1_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container.h"
v1_container_t* instantiate_v1_container(int include_optional);

#include "test_v1_lifecycle.c"
#include "test_v1_probe.c"
#include "test_v1_probe.c"
#include "test_v1_resource_requirements.c"
#include "test_v1_security_context.c"
#include "test_v1_probe.c"


v1_container_t* instantiate_v1_container(int include_optional) {
  v1_container_t* v1_container = NULL;
  if (include_optional) {
    v1_container = v1_container_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_lifecycle(0),
       // false, not to have infinite recursion
      instantiate_v1_probe(0),
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_v1_probe(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_requirements(0),
       // false, not to have infinite recursion
      instantiate_v1_security_context(0),
       // false, not to have infinite recursion
      instantiate_v1_probe(0),
      1,
      1,
      "0",
      "0",
      1,
      list_createList(),
      list_createList(),
      "0"
    );
  } else {
    v1_container = v1_container_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      "0",
      "0",
      NULL,
      NULL,
      "0",
      list_createList(),
      NULL,
      NULL,
      NULL,
      NULL,
      1,
      1,
      "0",
      "0",
      1,
      list_createList(),
      list_createList(),
      "0"
    );
  }

  return v1_container;
}


#ifdef v1_container_MAIN

void test_v1_container(int include_optional) {
    v1_container_t* v1_container_1 = instantiate_v1_container(include_optional);

	cJSON* jsonv1_container_1 = v1_container_convertToJSON(v1_container_1);
	printf("v1_container :\n%s\n", cJSON_Print(jsonv1_container_1));
	v1_container_t* v1_container_2 = v1_container_parseFromJSON(jsonv1_container_1);
	cJSON* jsonv1_container_2 = v1_container_convertToJSON(v1_container_2);
	printf("repeating v1_container:\n%s\n", cJSON_Print(jsonv1_container_2));
}

int main() {
  test_v1_container(1);
  test_v1_container(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_MAIN
#endif // v1_container_TEST
