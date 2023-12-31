#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"
#include "../../backend/semantic-analysis/symbol-table.h"

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */



// Programa.

Program ProgramGrammarAction(Mainscene mainscene);

Mainscene MainSceneGrammarAction(Body body, Expression expression);

Expression ExpressionEmptyGrammarAction();

Expression ExpressionFunctionGrammarAction(Function function, Expression to_expression);

Expression ExpressionConstanteGrammarAction(Constante to_constante, Expression to_expression);

Constante ConstanteGrammarAction(Value value);

Function FunctionGrammarAction(Type to_type, char * fun_name, ParametersDef parameters_def, Body to_body);

Type IntTypeGrammarAction();

Type TextTypeGrammarAction();

Type BoolTypeGrammarAction();

Type CharTypeGrammarAction();

Type RgbTypeGrammarAction();

Type BlockTypeGrammarAction();

Type GObjectTypeGrammarAction();

Type SceneTypeGrammarAction();

Type ButtonTypeGrammarAction();

Type StringTypeGrammarAction();

ParametersDef EmptyParametersDefGrammarAction();

ParametersDef ParametersDefGrammarAction(Type type , char* varname);

ParametersDef ParametersDefCommaGrammarAction(Type type , char* varname, ParametersDef parameters_def);

Parameters EmptyParametersGrammarAction();

Parameters ParametersGrammarAction(ReturnValue return_value);

Parameters ParametersCommaGrammarAction(ReturnValue return_value, Parameters parameters);

Body BodyEmptyGrammarAction();

Body BodyConditionalsGrammarAction(Conditionals conditionals, Body to_body);

Body BodyThisAssignRetGrammarAction(Array array, Assignment assignment, ReturnValue returnValue, Body to_body);

Body BodyFuncGrammarAction(Functionvalue functionvalue, Body to_body);

Body BodyThisArrayFuncGrammarAction(Array array,Functionvalue functionvalue ,Body to_body);

Body BodyThisArrayAssignFuncGrammarAction(Array array, Assignment assignment, Functionvalue functionvalue, Body to_body);

Body BodyTypeAssignConstGrammarAction(Type type, char * varname, Array array, Assignment assignment, Constant constant, Body to_body);

Body BodyTypeArrayGrammarAction(Type type, char* varname, Array array, Body to_body);

Body BodyTypeArrayAssignStringGrammarAction(Type type, char* varname, Array array, Assignment assignment, char * str ,Body to_body);

Body BodyVarArrayAssignConstGrammarAction(char* varname, Array array, Assignment assignment, Constant constant, Body to_body);

Body BodyVarArrayAssignFuncGrammarAction(char* varname, Array array, Assignment assignment, Functionvalue functionvalue, Body to_body);

Body BodyTypeVarArrayAssignFuncGrammarAction(Type type, char* varname, Array array, Assignment assignment, Functionvalue functionvalue, Body to_body);

Body BodyVarArraySingleGrammarAction(char* varname, Array array, VarSingleAction varsingleaction, Body to_body);

Body BodyRetGrammarAction(ReturnValue returnvalue);

Body BodyOnClickGrammarAction(Functionvalue functionvalue, Body to_body);

VarSingleAction IncrementVarSingleActionGrammarAction();

VarSingleAction DecrementVarSingleActionGrammarAction();

Assignment EqualAssignmentGrammarAction();

Assignment PlusEqualAssignmentGrammarAction();

Assignment MinusEqualAssignmentGrammarAction();

Assignment SlashEqualAssignmentGrammarAction();

Assignment MulEqualAssignmentGrammarAction();

FunctionAssignment FunctionAssignmentGrammarAction(Parameters to_parameters);

Array EmptyArrayGrammarAction();

Array VarnameArrayGrammarAction(char * arrayName, Array to_array);

Array IntegerArrayGrammarAction(int arrayValue, Array to_array);

Array ArrayArrayGrammarAction(Array to_array);

ReturnValue ReturnValueGrammarAction(Constant constant);

ReturnValue ReturnValueThisGrammarAction();

ReturnValue ReturnValueCharTextGrammarAction();

ReturnValue  ReturnValueGconstantGrammarAction(GConstant getconstant);

ReturnValue ReturnValueThisVarnameArrayGrammarAction(char* varname, Array array);

ReturnValue ReturnValueThisFunctionvalueGrammarAction(Functionvalue functionvalue);

ReturnValue  ReturnValueConstantSubGrammarAction(Constant constantLeft,Constant constantRight); 

ReturnValue  ReturnValueConstantAddGrammarAction(Constant constantLeft,Constant constantRight);

ReturnValue ReturnValueConstantMulGrammarAction(Constant constantLeft,Constant constantRight);

ReturnValue ReturnValueConstantDivGrammarAction(Constant constantLeft,Constant constantRight);

Value TypeValueGrammarAction(Type type);

Value FunctionValueValueGrammarAction(Functionvalue to_functionValue);

Functionvalue FunctionValueGrammarAction(char* varname, Parameters parameters);

Conditionals WhenBodyGrammarAction(GSBoolean to_boolean, Body to_body);

Conditionals WhenElseBodyGrammarAction(GSBoolean to_boolean, Body to_firstBody, Body to_secondBody);

Conditionals IfBodyGrammarAction(Negation to_negation, GSBoolean to_boolean, Body to_firstBody, IfOptions to_ifOptions);

Conditionals ForBodyGrammarAction(char * to_varName, int to_rightValue,Negation to_negation, GSBoolean to_boolean, ForOptions to_forOptions,Body to_firstBody);

Conditionals WhileBodyGrammarAction(Negation to_negation, GSBoolean to_boolean, Body to_firstBody);

Negation EmptyNegationGrammarAction();

Negation NegationGrammarAction();

ForOptions EmptyForOptionsGrammarAction();

ForOptions IncForOptionsGrammarAction(char * varname);

ForOptions DecForOptionsGrammarAction(char * varname);

ForOptions PlusEqualForOptionsGrammarAction(char * varname, int interger);

ForOptions MinusEqualForOptionsGrammarAction(char * varname, int interger);

ForOptions SlashEqualForOptionsGrammarAction(char * varname, int interger);

ForOptions MulEqualForOptionsGrammarAction(char * varname, int interger);

ForOptions EqualForOptionsGrammarAction(char * varname, Mathexp mathexp);

IfOptions EmptyIfOptionsGrammarAction();

IfOptions ElifBodyGrammarAction(GSBoolean boolean, Body body, IfOptions if_options);

IfOptions  ElseBodyGrammarAction(Body body);

GSBoolean MinorBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp);

GSBoolean MajorBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp);

GSBoolean MinorEqualBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp);

GSBoolean MajorEqualBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp);

GSBoolean EqualBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp);

GSBoolean NotEqualBooleanGrammarAction(Mathexp leftmathexp, Mathexp rightmathexp) ;

GSBoolean OrBooleanGrammarAction(GSBoolean leftboolean, GSBoolean rightboolean);

GSBoolean AndBooleanGrammarAction(GSBoolean leftboolean, GSBoolean rightboolean);

GSBoolean InVarBooleanGrammarAction(char * varname, char * varname2);

GSBoolean InGCBooleanGrammarAction(char * varname, GConstant gconstant);

GSBoolean VarnameBooleanGrammarAction(char * var);

GSBoolean VarnameFuncBooleanGrammarAction(char * var, FunctionAssignment functionAssignment);

GSBoolean HitsVarBooleanGrammarAction(char * varname, char * varname2);

GSBoolean HitsGCBooleanGrammarAction(char * var, GConstant gconstant);

GSBoolean ConditionalsBooleanGrammarAction(Conditionals conditionals);

Mathexp SubtractionExpressionGrammarAction(Mathexp leftMathexp, Mathexp rightMathexp);

Mathexp MultiplicationExpressionGrammarAction(Mathexp leftMathexp, Mathexp rightMathexp);

Mathexp DivisionExpressionGrammarAction(Mathexp leftMathexp, Mathexp rightMathexp);

Mathexp FactorExpressionGrammarAction(Factor factor);

Mathexp AdditionExpressionGrammarAction(Mathexp leftMathexp, Mathexp rightMathexp);

Factor MathExpFactorGrammarAction(Mathexp mathexp);

Factor ConstantFactorGrammarAction(Constant constant);

Constant IntegerConstantGrammarAction(int value);

Constant ConstantVarnameGrammarAction(char * varname);

Constant ConstantSubstractIntegerGrammarAction(int value);

Constant IntegerPxConstantGrammarAction(int value);

Constant StringConstantGrammarAction(char * str);

GConstant UpBorderConstantGrammarAction();

GConstant DownBorderConstantGrammarAction();

GConstant LeftBorderConstantGrammarAction();

GConstant RightBorderConstantGrammarAction();

GConstant UpConstantGrammarAction();

GConstant DownConstantGrammarAction();

GConstant LeftConstantGrammarAction();

GConstant RightConstantGrammarAction();

GConstant SpaceConstantGrammarAction();

GConstant EnterConstantGrammarAction();

GConstant NokeyConstantGrammarAction();

#endif
