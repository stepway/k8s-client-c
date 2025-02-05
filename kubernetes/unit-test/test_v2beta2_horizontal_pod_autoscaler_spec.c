#ifndef v2beta2_horizontal_pod_autoscaler_spec_TEST
#define v2beta2_horizontal_pod_autoscaler_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_horizontal_pod_autoscaler_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_horizontal_pod_autoscaler_spec.h"
v2beta2_horizontal_pod_autoscaler_spec_t* instantiate_v2beta2_horizontal_pod_autoscaler_spec(int include_optional);

#include "test_v2beta2_horizontal_pod_autoscaler_behavior.c"
#include "test_v2beta2_cross_version_object_reference.c"


v2beta2_horizontal_pod_autoscaler_spec_t* instantiate_v2beta2_horizontal_pod_autoscaler_spec(int include_optional) {
  v2beta2_horizontal_pod_autoscaler_spec_t* v2beta2_horizontal_pod_autoscaler_spec = NULL;
  if (include_optional) {
    v2beta2_horizontal_pod_autoscaler_spec = v2beta2_horizontal_pod_autoscaler_spec_create(
       // false, not to have infinite recursion
      instantiate_v2beta2_horizontal_pod_autoscaler_behavior(0),
      56,
      list_createList(),
      56,
       // false, not to have infinite recursion
      instantiate_v2beta2_cross_version_object_reference(0)
    );
  } else {
    v2beta2_horizontal_pod_autoscaler_spec = v2beta2_horizontal_pod_autoscaler_spec_create(
      NULL,
      56,
      list_createList(),
      56,
      NULL
    );
  }

  return v2beta2_horizontal_pod_autoscaler_spec;
}


#ifdef v2beta2_horizontal_pod_autoscaler_spec_MAIN

void test_v2beta2_horizontal_pod_autoscaler_spec(int include_optional) {
    v2beta2_horizontal_pod_autoscaler_spec_t* v2beta2_horizontal_pod_autoscaler_spec_1 = instantiate_v2beta2_horizontal_pod_autoscaler_spec(include_optional);

	cJSON* jsonv2beta2_horizontal_pod_autoscaler_spec_1 = v2beta2_horizontal_pod_autoscaler_spec_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec_1);
	printf("v2beta2_horizontal_pod_autoscaler_spec :\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_spec_1));
	v2beta2_horizontal_pod_autoscaler_spec_t* v2beta2_horizontal_pod_autoscaler_spec_2 = v2beta2_horizontal_pod_autoscaler_spec_parseFromJSON(jsonv2beta2_horizontal_pod_autoscaler_spec_1);
	cJSON* jsonv2beta2_horizontal_pod_autoscaler_spec_2 = v2beta2_horizontal_pod_autoscaler_spec_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec_2);
	printf("repeating v2beta2_horizontal_pod_autoscaler_spec:\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_spec_2));
}

int main() {
  test_v2beta2_horizontal_pod_autoscaler_spec(1);
  test_v2beta2_horizontal_pod_autoscaler_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_horizontal_pod_autoscaler_spec_MAIN
#endif // v2beta2_horizontal_pod_autoscaler_spec_TEST
