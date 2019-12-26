
struct Node
{
    int tag;					// �ڵ�����
    char* value;				// �ڵ�ֵ����Ҫ���id��type
    struct Node *childs[10];	// �ӽڵ�
    int nchilds;				// 	�ӽڵ����
	int lineno;					// �к�
};

//typedef struct Node_ Node;

struct Node *createLeaf(int tag, char *text);
struct Node *createNode(int tag, int nchilds, struct Node *a[]);
struct Node *createEmpty();
void treePrint(struct Node * nd);
char * getTag(int tag);
enum yyNTtype
{
	PROGRAM = 400,
	EXTDEFLIST = 401,
	EXTDEF = 402,
	SPECIFIER = 403,
	EXTDECLIST = 404,
	STRUCTSPECIFIER = 405,
	OPTTAG = 406,
	TAG = 407,
	VARDEC = 408,
	FUNDEC = 409,
	VARLIST = 410,
	PARAMDEC = 411,
	COMPST = 412,
	STMTLIST = 413,
	STMT = 414,
	DEFLIST = 415,
	DEF = 416,
	DECLIST = 417,
	DEC = 418,
	EXP = 419,
	ARGS = 420,

};
