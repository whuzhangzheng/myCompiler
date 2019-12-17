
#include"sequence_fb.tab.h"

%%

[ \t]		{}
\n		{return EOL;}
.*		{return WORD;}

