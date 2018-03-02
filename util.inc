// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_util
	#undef _inc_util
#endif
// custom include-guard to ensure we don't duplicate
#if defined _util_included
	#endinput
#endif
#define _util_included


#include "math.inc"
