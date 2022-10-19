#include "CUnit/Basic.h"
#include "../header/function.h"

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */

int init_suite_writetofile(void) 
{
	return 0;
}
/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_writetofile(void) 
{
	return 0;
}

void writetofile_sunnycases(void) 
{
  	CU_ASSERT_EQUAL(writetofile("hello","eng","gem","halllo","1"), 1);
	CU_ASSERT_EQUAL(writetofile("hola","fre","gem","halllo","1"), 1);
	CU_ASSERT_EQUAL(writetofile("bonjour","gem","eng","welcome","1"), 1);
	
	
}

void writetofile_rainycases(void) 
{
	CU_ASSERT_EQUAL(writetofile("hello","","","",""), 0);
	CU_ASSERT_EQUAL(writetofile("hola","eng","","hi","1"), 0);
	CU_ASSERT_EQUAL(writetofile("welcome","gem","","bonjour","1"), 0);
    	
}

int init_suite_modify(void) 
{
	return 0;
}

int clean_suite_modify(void) 
{
	return 0;
}

void modify_sunnycases(void)
{
	CU_ASSERT_EQUAL(modify("English_German.txt","Happy","Make"), 1);
	CU_ASSERT_EQUAL(modify("German_English.txt","Wald","Make"), 1);
	CU_ASSERT_EQUAL(modify("French_German.txt","Heureux","Make"), 1);
}

void modify_rainycases(void)
{
	CU_ASSERT_EQUAL(modify("engh_erman.txt","Happy","Make"), 0);
	CU_ASSERT_EQUAL(modify("abcd","Happy","Make"), 0);
}

int init_suite_delete(void) 
{
	return 0;
}
/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_delete(void) 
{
	return 0;
}

void delete_sunnycases(void) 
{
  	CU_ASSERT_EQUAL(delete("English_German.txt","Make"), 1);
	CU_ASSERT_EQUAL(delete("German_English.txt","Make"), 1);
	CU_ASSERT_EQUAL(delete("French_German.txt","Make"), 1);
	
	
}

void delete_rainycases(void) 
{
	CU_ASSERT_EQUAL(delete("engh_erman.txt","Happy"), 0);
	CU_ASSERT_EQUAL(delete("French_German.txt","xyz"), 0);
    	
}

int init_suite_translate(void) 
{
	return 0;
}
/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_translate(void) 
{
	return 0;
}

void translate_sunnycases(void) 
{
  	CU_ASSERT_EQUAL(translate("Hallo","German","French"), 1);
	CU_ASSERT_EQUAL(translate("Contento","Spanish","English"), 1);
	CU_ASSERT_EQUAL(translate("Bosque","Spanish","German"), 1);
	
	
}

void translate_rainycases(void) 
{
	CU_ASSERT_EQUAL(translate("","Happy","abc"), 0);
	CU_ASSERT_EQUAL(translate("healo","Spanish","German"), 0);
	CU_ASSERT_EQUAL(translate("Hello","panish","German"), 0);
	
    	
}
