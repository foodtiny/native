#include "../builtin.h"
#include "../unit_test.h"

TEST(General, JoinPointerPointerChar) {
    char *target[] = {
            (char *) "The",
            (char *) "quick",
            (char *) "brown",
            (char *) "fox",
            (char *) "jumps",
            (char *) "over",
            (char *) "the",
            (char *) "lazy",
            (char *) "dog",
            '\0'
    };
    char *expect = "Thequickbrownfoxjumpsoverthelazydog";
    ASSERT_STR(expect, join_pointer_pointer_char(target));
}

TEST(General, JoinDelimPointerPointerChar) {
	char *target[] = {
			(char *) "The",
			(char *) "quick",
			(char *) "brown",
			(char *) "fox",
			(char *) "jumps",
			(char *) "over",
			(char *) "the",
			(char *) "lazy",
			(char *) "dog",
			'\0'
	};
	char *delim = "|";
	char *expect = "The|quick|brown|fox|jumps|over|the|lazy|dog";
	ASSERT_STR(expect, join_delim_pointer_pointer_char(target, delim));
}
