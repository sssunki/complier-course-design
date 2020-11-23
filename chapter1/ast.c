#include "def.h"
#include "parser.tab.h"

struct ASTNode * mknode(int num,int kind,int pos,...){
    struct ASTNode *T=(struct ASTNode *)calloc(sizeof(struct ASTNode),1);
    int i=0;
    T->kind=kind;
    T->pos=pos;
    va_list pArgs;
    va_start(pArgs, pos);
    for(i=0;i<num;i++)
        T->ptr[i]= va_arg(pArgs, struct ASTNode *);
    while (i<4) T->ptr[i++]=NULL;
    va_end(pArgs);
    return T;
}


void display(struct ASTNode *T,int indent)
{
  int i=1;
  struct ASTNode *T0;
  if (T)
	{
	switch (T->kind) {
	case EXT_DEF_LIST:  display(T->ptr[0],indent);    
                        display(T->ptr[1],indent);    
                        break;
	case EXT_VAR_DEF:   printf("%*c var define：(%d)\n",indent,' ',T->pos);
                        display(T->ptr[0],indent+3);        
                        printf("%*c var name：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);        
                        break;
	case TYPE:          printf("%*c type： %s\n",indent,' ',T->type_id);
                        break;
    case EXT_DEC_LIST:  display(T->ptr[0],indent);     
                        display(T->ptr[1],indent);     
                        break;
	case FUNC_DEF:      printf("%*c func define：(%d)\n",indent,' ',T->pos);
                        display(T->ptr[0],indent+3);      
                        display(T->ptr[1],indent+3);      
                        display(T->ptr[2],indent+3);     
                        break;
	case FUNC_DEC:      printf("%*c func name：%s\n",indent,' ',T->type_id);
                        if (T->ptr[0]) {
                                printf("%*c params：\n",indent,' ');
                                display(T->ptr[0],indent+3);  
                                }
                        else printf("%*c no param func \n",indent+3,' ');
                        break;
	case PARAM_LIST:    display(T->ptr[0],indent);    
                        display(T->ptr[1],indent);
                        break;
	case PARAM_DEC:     printf("%*c type：%s, param name：%s\n",indent,' ',T->ptr[0]->type==INT?"int":"float",T->ptr[1]->type_id);
                        break;
	case EXP_STMT:      printf("%*c exp statement：(%d)\n",indent,' ',T->pos);
                        display(T->ptr[0],indent+3);
                        break;
	case RETURN:        printf("%*c return ：(%d)\n",indent,' ',T->pos);
                        display(T->ptr[0],indent+3);
                        break;
	case COMP_STM:      printf("%*c comp statement ：(%d)\n",indent,' ',T->pos);
                        printf("%*c var define in comp statement：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      
                        printf("%*c statement in comp statement：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      
                        break;
	case STM_LIST:      display(T->ptr[0],indent);      
                        display(T->ptr[1],indent);        
                        break;
	case WHILE:         printf("%*c while statemnt：(%d)\n",indent,' ',T->pos);
                        printf("%*c while condition：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      
                        printf("%*c while body：(%d)\n",indent+3,' ',T->pos);
                        display(T->ptr[1],indent+6);     
                        break;
	case IF_THEN:       printf("%*c if no else statement：(%d)\n",indent,' ',T->pos);
                        printf("%*c condition：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);     
                        printf("%*c if statement：(%d)\n",indent+3,' ',T->pos);
                        display(T->ptr[1],indent+6);      
                        break;
	case IF_THEN_ELSE:  printf("%*c if than else statement：(%d)\n",indent,' ',T->pos);
                        printf("%*c condition：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);     
                        printf("%*c if statement ：(%d)\n",indent+3,' ',T->pos);
                        display(T->ptr[1],indent+6);      
                        printf("%*c else statement：(%d)\n",indent+3,' ',T->pos);
                        display(T->ptr[2],indent+6);      
                        break;
    case DEF_LIST:      display(T->ptr[0],indent);    
                        display(T->ptr[1],indent);    
                        break;
    case VAR_DEF:       printf("%*c var define：(%d)\n",indent,' ',T->pos);
                        display(T->ptr[0],indent+3);   
                        display(T->ptr[1],indent+3);   
                        break;
    case DEC_LIST:      printf("%*c var name：\n",indent,' ');
                        T0=T;
                        while (T0) {
                            if (T0->ptr[0]->kind==ID)
                                printf("%*c %s\n",indent+6,' ',T0->ptr[0]->type_id);
                            else if (T0->ptr[0]->kind==ASSIGNOP)
                                {
                                printf("%*c %s ASSIGNOP\n ",indent+6,' ',T0->ptr[0]->ptr[0]->type_id);
                                display(T0->ptr[0]->ptr[1],indent+strlen(T0->ptr[0]->ptr[0]->type_id)+7);        
                                }
                            T0=T0->ptr[1];
                            }
                        break;
	case ID:	        printf("%*cID： %s\n",indent,' ',T->type_id);
                        break;
	case INT:	        printf("%*cINT：%d\n",indent,' ',T->type_int);
                        break;
	case FLOAT:	        printf("%*cFLOAT：%f\n",indent,' ',T->type_float);
                        break;
	case ASSIGNOP:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:
                    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    display(T->ptr[1],indent+3);
                    break;
	case NOT:
	case UMINUS:    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
    case FUNC_CALL: printf("%*c func call：(%d)\n",indent,' ',T->pos);
                    printf("%*c func name：%s\n",indent+3,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
	case ARGS:      i=1;
                    while (T) {  
                        struct ASTNode *T0=T->ptr[0];
                        printf("%*c第%d个实际参数表达式：\n",indent,' ',i++);
                        display(T0,indent+3);
                        T=T->ptr[1];
                        }
                    printf("\n");
                    break;
         }
      }
}