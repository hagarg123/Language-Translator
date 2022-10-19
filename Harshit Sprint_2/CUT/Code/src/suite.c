#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "CUnit/Basic.h"
#include "../header/suite.h"
#include "../header/function.h"

#define SUCCESS 1
#define FAILURE 0
int main() 
{
	
/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
	CU_pSuite pSuite1 = NULL;
  	CU_pSuite pSuite2 = NULL;
	CU_pSuite pSuite3 = NULL;
	CU_pSuite pSuite4 = NULL;
/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
/* add a suite to the registry */
	pSuite1 = CU_add_suite("suite writetofile...", init_suite_writetofile, clean_suite_writetofile);
  
	if (NULL == pSuite1) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
  /* add a suite to the registry */
	pSuite2 = CU_add_suite("suite modify...", init_suite_modify, clean_suite_modify);
	
	if (NULL == pSuite2) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
	
	pSuite3 = CU_add_suite("suite delete...", init_suite_delete, clean_suite_delete);
	
	if (NULL == pSuite3) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
	
	pSuite4 = CU_add_suite("suite translate...", init_suite_translate, clean_suite_translate);
	
	if (NULL == pSuite3) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
 /* add the tests to the suite */
  	if ((NULL == CU_add_test(pSuite1, "Test for writetofile() in sunny cases", writetofile_sunnycases)) || (NULL == CU_add_test(pSuite1, "Test for writetofile() in rainy cases", writetofile_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
 /* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite2, "Test for modify() in sunny cases", modify_sunnycases)) || (NULL == CU_add_test(pSuite2, "Test for modify() in rainy cases", modify_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
	
	if ((NULL == CU_add_test(pSuite3, "Test for delete() in sunny cases", delete_sunnycases)) || (NULL == CU_add_test(pSuite3, "Test for delete() in rainy cases", delete_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}

	if ((NULL == CU_add_test(pSuite4, "Test for translate() in sunny cases", translate_sunnycases)) || (NULL == CU_add_test(pSuite4, "Test for translate() in rainy cases", translate_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
 /* Run all tests using the CUnit Basic interface */
  	CU_basic_set_mode(CU_BRM_VERBOSE);
  	CU_basic_run_tests();
  	CU_cleanup_registry();
	
	
  	
	return CU_get_error();
}

