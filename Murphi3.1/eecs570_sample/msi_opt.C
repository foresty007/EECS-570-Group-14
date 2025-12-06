/******************************
  Program "msi_opt.m" compiled by "Murphi Release 3.1"

  Murphi Last Modefied Date: "Jan 29 1999"
  Murphi Last Compiled date: "Oct 23 2025"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Murphi Release 3.1"
#define MURPHI_DATE "Jan 29 1999"
#define PROTOCOL_NAME "msi_opt"
#define BITS_IN_WORLD 19592
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Proc (char *name, int os): mu__byte(1, 6, 3, name, os) {};
  mu_1_Proc (void): mu__byte(1, 6, 3) {};
  mu_1_Proc (int val): mu__byte(1, 6, 3, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2","Proc_3","Proc_4","Proc_5","Proc_6",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
  {
    if (val.defined())
      return ( s << mu_1_Home::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_Home (char *name, int os): mu__byte(7, 8, 2, name, os) {};
  mu_1_Home (void): mu__byte(7, 8, 2) {};
  mu_1_Home (int val): mu__byte(7, 8, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Home::values[] = {"Home0","Home1",NULL };

/*** end of enum declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_UQIDType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_UQIDType& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_UQIDType& val)
    {
      if (val.defined())
        return ( s << mu_1_UQIDType::values[ int(val) - 9 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_UQIDType (char *name, int os): mu__byte(9, 9, 1, name, os) {};
  mu_1_UQIDType (void): mu__byte(9, 9, 1) {};
  mu_1_UQIDType (int val): mu__byte(9, 9, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -9]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 9] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_UQIDType& a, mu_1_UQIDType& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_UQIDType::values[] =
  { "UQIDType_1",NULL };

/*** end scalarset declaration ***/
mu_1_UQIDType mu_1_UQIDType_undefined_var;

class mu_1_MESIType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MESIType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MESIType& val)
  {
    if (val.defined())
      return ( s << mu_1_MESIType::values[ int(val) - 10] );
    else return ( s << "Undefined" );
  };

  mu_1_MESIType (char *name, int os): mu__byte(10, 13, 3, name, os) {};
  mu_1_MESIType (void): mu__byte(10, 13, 3) {};
  mu_1_MESIType (int val): mu__byte(10, 13, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -10]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -10] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MESIType::values[] = {"M","E","S","I",NULL };

/*** end of enum declaration ***/
mu_1_MESIType mu_1_MESIType_undefined_var;

class mu_1_RspData: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_RspData& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_RspData& val)
    {
      if (val.defined())
        return ( s << mu_1_RspData::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_RspData (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_RspData (void): mu__byte(0, 4, 3) {};
  mu_1_RspData (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 9) && (value() <= 9)) return (value() - 9);
    if ((value() >= 10) && (value() <= 13)) return (value() - 9);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+9);
    if (val >= 1 && val <= 4) return value(val+9);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_RspData& a, mu_1_RspData& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_RspData::values[] = {"UQIDType_1","M","E","S","I",NULL };

/*** end union declaration ***/
mu_1_RspData mu_1_RspData_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Value& val) { return mu__byte::operator=((int) val); };
  mu_1_Value (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_Value (void): mu__byte(0, 2, 2) {};
  mu_1_Value (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Value mu_1_Value_undefined_var;

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Address& val) { return mu__byte::operator=((int) val); };
  mu_1_Address (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_Address (void): mu__byte(0, 2, 2) {};
  mu_1_Address (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Address mu_1_Address_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
        return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (char *name, int os): mu__byte(0, 7, 4, name, os) {};
  mu_1_Node (void): mu__byte(0, 7, 4) {};
  mu_1_Node (int val): mu__byte(0, 7, 4, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 7) && (value() <= 8)) return (value() - 7);
    if ((value() >= 1) && (value() <= 6)) return (value() - -1);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 1) return value(val+7);
    if (val >= 2 && val <= 7) return value(val+-1);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_Node::values[] = {"Home0","Home1","Proc_1","Proc_2","Proc_3","Proc_4","Proc_5","Proc_6",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_VCType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_VCType& val) { return mu__byte::operator=((int) val); };
  mu_1_VCType (char *name, int os): mu__byte(0, 5, 3, name, os) {};
  mu_1_VCType (void): mu__byte(0, 5, 3) {};
  mu_1_VCType (int val): mu__byte(0, 5, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_VCType mu_1_VCType_undefined_var;

class mu_1_SharerNum: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_SharerNum& val) { return mu__byte::operator=((int) val); };
  mu_1_SharerNum (char *name, int os): mu__byte(0, 6, 3, name, os) {};
  mu_1_SharerNum (void): mu__byte(0, 6, 3) {};
  mu_1_SharerNum (int val): mu__byte(0, 6, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_SharerNum mu_1_SharerNum_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 14] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (char *name, int os): mu__byte(14, 45, 6, name, os) {};
  mu_1_MessageType (void): mu__byte(14, 45, 6) {};
  mu_1_MessageType (int val): mu__byte(14, 45, 6, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -14]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -14] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MessageType::values[] = {"RdCurr","RdOwn","RdShared","RdAny","RdOwnNoData","ItoMWr","WrCur","CLFlush","CleanEvict","DirtyEvict","CleanEvictNoData","WrInv","CacheFlushed","RspIHitI","RspVHitV","RspIHitSE","RspSHitSE","RspSFwdM","RspIFwdM","RspVFwdV","WritePull","GO","GO_WritePull","ExtCmp","GO_WritePull_Drop","Reserved","Fast_GO_WritePull","GO_ERR_WritePull","SnpData","SnpInv","SnpCur","Data",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 1, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 1, 2) {};
  mu_1__type_1 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 1, 2) {};
  mu_1__type_2 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_3& val) { return mu__byte::operator=((int) val); };
  mu_1__type_3 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_3 (void): mu__byte(0, 1, 2) {};
  mu_1__type_3 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_4& val) { return mu__byte::operator=((int) val); };
  mu_1__type_4 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_4 (void): mu__byte(0, 1, 2) {};
  mu_1__type_4 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_5& val) { return mu__byte::operator=((int) val); };
  mu_1__type_5 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_5 (void): mu__byte(0, 1, 2) {};
  mu_1__type_5 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_6& val) { return mu__byte::operator=((int) val); };
  mu_1__type_6 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_6 (void): mu__byte(0, 3, 3) {};
  mu_1__type_6 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_valid;
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_VCType mu_vc;
  mu_1_Value mu_val;
  mu_1_Address mu_addr;
  mu_1_UQIDType mu_cqid;
  mu_1_UQIDType mu_uqid;
  mu_1__type_1 mu_nt;
  mu_1__type_2 mu_chunkvalid;
  mu_1__type_3 mu_poison;
  mu_1__type_4 mu_bogus;
  mu_1__type_5 mu_go_err;
  mu_1_RspData mu_rspdata;
  mu_1__type_6 mu_rsp_pre;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_valid, b.mu_valid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_addr, b.mu_addr);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cqid, b.mu_cqid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_uqid, b.mu_uqid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_nt, b.mu_nt);
    if (w!=0) return w;
    w = CompareWeight(a.mu_chunkvalid, b.mu_chunkvalid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_poison, b.mu_poison);
    if (w!=0) return w;
    w = CompareWeight(a.mu_bogus, b.mu_bogus);
    if (w!=0) return w;
    w = CompareWeight(a.mu_go_err, b.mu_go_err);
    if (w!=0) return w;
    w = CompareWeight(a.mu_rspdata, b.mu_rspdata);
    if (w!=0) return w;
    w = CompareWeight(a.mu_rsp_pre, b.mu_rsp_pre);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_valid, b.mu_valid);
    if (w!=0) return w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_addr, b.mu_addr);
    if (w!=0) return w;
    w = Compare(a.mu_cqid, b.mu_cqid);
    if (w!=0) return w;
    w = Compare(a.mu_uqid, b.mu_uqid);
    if (w!=0) return w;
    w = Compare(a.mu_nt, b.mu_nt);
    if (w!=0) return w;
    w = Compare(a.mu_chunkvalid, b.mu_chunkvalid);
    if (w!=0) return w;
    w = Compare(a.mu_poison, b.mu_poison);
    if (w!=0) return w;
    w = Compare(a.mu_bogus, b.mu_bogus);
    if (w!=0) return w;
    w = Compare(a.mu_go_err, b.mu_go_err);
    if (w!=0) return w;
    w = Compare(a.mu_rspdata, b.mu_rspdata);
    if (w!=0) return w;
    w = Compare(a.mu_rsp_pre, b.mu_rsp_pre);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_valid.MultisetSort();
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_vc.MultisetSort();
    mu_val.MultisetSort();
    mu_addr.MultisetSort();
    mu_cqid.MultisetSort();
    mu_uqid.MultisetSort();
    mu_nt.MultisetSort();
    mu_chunkvalid.MultisetSort();
    mu_poison.MultisetSort();
    mu_bogus.MultisetSort();
    mu_go_err.MultisetSort();
    mu_rspdata.MultisetSort();
    mu_rsp_pre.MultisetSort();
  }
  void print_statistic()
  {
    mu_valid.print_statistic();
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_vc.print_statistic();
    mu_val.print_statistic();
    mu_addr.print_statistic();
    mu_cqid.print_statistic();
    mu_uqid.print_statistic();
    mu_nt.print_statistic();
    mu_chunkvalid.print_statistic();
    mu_poison.print_statistic();
    mu_bogus.print_statistic();
    mu_go_err.print_statistic();
    mu_rspdata.print_statistic();
    mu_rsp_pre.print_statistic();
  }
  void clear() {
    mu_valid.clear();
    mu_mtype.clear();
    mu_src.clear();
    mu_vc.clear();
    mu_val.clear();
    mu_addr.clear();
    mu_cqid.clear();
    mu_uqid.clear();
    mu_nt.clear();
    mu_chunkvalid.clear();
    mu_poison.clear();
    mu_bogus.clear();
    mu_go_err.clear();
    mu_rspdata.clear();
    mu_rsp_pre.clear();
 };
  void undefine() {
    mu_valid.undefine();
    mu_mtype.undefine();
    mu_src.undefine();
    mu_vc.undefine();
    mu_val.undefine();
    mu_addr.undefine();
    mu_cqid.undefine();
    mu_uqid.undefine();
    mu_nt.undefine();
    mu_chunkvalid.undefine();
    mu_poison.undefine();
    mu_bogus.undefine();
    mu_go_err.undefine();
    mu_rspdata.undefine();
    mu_rsp_pre.undefine();
 };
  void reset() {
    mu_valid.reset();
    mu_mtype.reset();
    mu_src.reset();
    mu_vc.reset();
    mu_val.reset();
    mu_addr.reset();
    mu_cqid.reset();
    mu_uqid.reset();
    mu_nt.reset();
    mu_chunkvalid.reset();
    mu_poison.reset();
    mu_bogus.reset();
    mu_go_err.reset();
    mu_rspdata.reset();
    mu_rsp_pre.reset();
 };
  void print() {
    mu_valid.print();
    mu_mtype.print();
    mu_src.print();
    mu_vc.print();
    mu_val.print();
    mu_addr.print();
    mu_cqid.print();
    mu_uqid.print();
    mu_nt.print();
    mu_chunkvalid.print();
    mu_poison.print();
    mu_bogus.print();
    mu_go_err.print();
    mu_rspdata.print();
    mu_rsp_pre.print();
  };
  void print_diff(state *prevstate) {
    mu_valid.print_diff(prevstate);
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_vc.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_addr.print_diff(prevstate);
    mu_cqid.print_diff(prevstate);
    mu_uqid.print_diff(prevstate);
    mu_nt.print_diff(prevstate);
    mu_chunkvalid.print_diff(prevstate);
    mu_poison.print_diff(prevstate);
    mu_bogus.print_diff(prevstate);
    mu_go_err.print_diff(prevstate);
    mu_rspdata.print_diff(prevstate);
    mu_rsp_pre.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_valid.to_state(thestate);
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_vc.to_state(thestate);
    mu_val.to_state(thestate);
    mu_addr.to_state(thestate);
    mu_cqid.to_state(thestate);
    mu_uqid.to_state(thestate);
    mu_nt.to_state(thestate);
    mu_chunkvalid.to_state(thestate);
    mu_poison.to_state(thestate);
    mu_bogus.to_state(thestate);
    mu_go_err.to_state(thestate);
    mu_rspdata.to_state(thestate);
    mu_rsp_pre.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_valid.value(from.mu_valid.value());
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_vc.value(from.mu_vc.value());
    mu_val.value(from.mu_val.value());
    mu_addr.value(from.mu_addr.value());
    mu_cqid.value(from.mu_cqid.value());
    mu_uqid.value(from.mu_uqid.value());
    mu_nt.value(from.mu_nt.value());
    mu_chunkvalid.value(from.mu_chunkvalid.value());
    mu_poison.value(from.mu_poison.value());
    mu_bogus.value(from.mu_bogus.value());
    mu_go_err.value(from.mu_go_err.value());
    mu_rspdata.value(from.mu_rspdata.value());
    mu_rsp_pre.value(from.mu_rsp_pre.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_valid.set_self_2(name, ".valid", os + 0 );
  mu_mtype.set_self_2(name, ".mtype", os + 8 );
  mu_src.set_self_2(name, ".src", os + 16 );
  mu_vc.set_self_2(name, ".vc", os + 24 );
  mu_val.set_self_2(name, ".val", os + 32 );
  mu_addr.set_self_2(name, ".addr", os + 40 );
  mu_cqid.set_self_2(name, ".cqid", os + 48 );
  mu_uqid.set_self_2(name, ".uqid", os + 56 );
  mu_nt.set_self_2(name, ".nt", os + 64 );
  mu_chunkvalid.set_self_2(name, ".chunkvalid", os + 72 );
  mu_poison.set_self_2(name, ".poison", os + 80 );
  mu_bogus.set_self_2(name, ".bogus", os + 88 );
  mu_go_err.set_self_2(name, ".go_err", os + 96 );
  mu_rspdata.set_self_2(name, ".rspdata", os + 104 );
  mu_rsp_pre.set_self_2(name, ".rsp_pre", os + 112 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_7: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_7& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_7& val)
  {
    if (val.defined())
      return ( s << mu_1__type_7::values[ int(val) - 46] );
    else return ( s << "Undefined" );
  };

  mu_1__type_7 (char *name, int os): mu__byte(46, 78, 6, name, os) {};
  mu_1__type_7 (void): mu__byte(46, 78, 6) {};
  mu_1__type_7 (int val): mu__byte(46, 78, 6, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -46]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -46] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_7::values[] = {"H_M","H_E","H_S","H_I","HT_SI_A","HT_SE_A","HT_II_D","HT_II_AD","HT_IS_A","HT_MM_AD","HT_MM_A","HT_MM_D","HT_MI_AD","HT_MI_D","HT_MI_A","HT_MI_AD1","HT_MI_A1","HT_MI_D1","HT_ME_AD","HT_ME_A","HT_ME_D","HT_EI_AD","HT_EI_A","HT_EI_D","HT_EE_AD","HT_EE_A","HT_EE_D","HT_ES_AD","HT_ES_A","HT_ES_D","HT_MS_AD","HT_MS_D","HT_MS_A",NULL };

/*** end of enum declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_8_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_8_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_8_id () : mu__byte(0,5,0) {};
  mu_1__type_8_id (int val) : mu__byte(0,5,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_8
{
 public:
  mu_1_Node array[ 6 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 6 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_8 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_8 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_8 ();
  mu_1_Node& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 5) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
    for (int i = 0; i < 6; i++)
    {
        array[i].value(from.array[i].value());
        valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 6; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 6; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 6; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 6; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 6; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 6; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_8_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 6; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 6; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Node &element)
  {
    update_size();
    if (current_size >= 6) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 6; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_8_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Node temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 6; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 6; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 6; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_8::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_8::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 6; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os);
  k = os + i * 8;
  for(i = 0; i < 6; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_8::~mu_1__type_8()
{
}
/*** end multiset declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_9& val) { return mu__byte::operator=((int) val); };
  mu_1__type_9 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_9 (void): mu__byte(0, 1, 2) {};
  mu_1__type_9 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_10& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_10& val)
  {
    if (val.defined())
      return ( s << mu_1__type_10::values[ int(val) - 79] );
    else return ( s << "Undefined" );
  };

  mu_1__type_10 (char *name, int os): mu__byte(79, 83, 3, name, os) {};
  mu_1__type_10 (void): mu__byte(79, 83, 3) {};
  mu_1__type_10 (int val): mu__byte(79, 83, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -79]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -79] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_10::values[] = {"flag_EM_D","flag_EI_D","flag_EE_D","flag_ES_D","flag_SI_A",NULL };

/*** end of enum declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_7 mu_state;
  mu_1_Node mu_owner;
  mu_1__type_8 mu_sharers;
  mu_1_Value mu_val;
  mu_1_Node mu_requester;
  mu_1_MessageType mu_request_type;
  mu_1__type_9 mu_request_pre;
  mu_1__type_10 mu_flag;
  mu_1_HomeState ( char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_requester, b.mu_requester);
    if (w!=0) return w;
    w = CompareWeight(a.mu_request_type, b.mu_request_type);
    if (w!=0) return w;
    w = CompareWeight(a.mu_request_pre, b.mu_request_pre);
    if (w!=0) return w;
    w = CompareWeight(a.mu_flag, b.mu_flag);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_requester, b.mu_requester);
    if (w!=0) return w;
    w = Compare(a.mu_request_type, b.mu_request_type);
    if (w!=0) return w;
    w = Compare(a.mu_request_pre, b.mu_request_pre);
    if (w!=0) return w;
    w = Compare(a.mu_flag, b.mu_flag);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_owner.MultisetSort();
    mu_sharers.MultisetSort();
    mu_val.MultisetSort();
    mu_requester.MultisetSort();
    mu_request_type.MultisetSort();
    mu_request_pre.MultisetSort();
    mu_flag.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_owner.print_statistic();
    mu_sharers.print_statistic();
    mu_val.print_statistic();
    mu_requester.print_statistic();
    mu_request_type.print_statistic();
    mu_request_pre.print_statistic();
    mu_flag.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_owner.clear();
    mu_sharers.clear();
    mu_val.clear();
    mu_requester.clear();
    mu_request_type.clear();
    mu_request_pre.clear();
    mu_flag.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_owner.undefine();
    mu_sharers.undefine();
    mu_val.undefine();
    mu_requester.undefine();
    mu_request_type.undefine();
    mu_request_pre.undefine();
    mu_flag.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_owner.reset();
    mu_sharers.reset();
    mu_val.reset();
    mu_requester.reset();
    mu_request_type.reset();
    mu_request_pre.reset();
    mu_flag.reset();
 };
  void print() {
    mu_state.print();
    mu_owner.print();
    mu_sharers.print();
    mu_val.print();
    mu_requester.print();
    mu_request_type.print();
    mu_request_pre.print();
    mu_flag.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_sharers.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_requester.print_diff(prevstate);
    mu_request_type.print_diff(prevstate);
    mu_request_pre.print_diff(prevstate);
    mu_flag.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_sharers.to_state(thestate);
    mu_val.to_state(thestate);
    mu_requester.to_state(thestate);
    mu_request_type.to_state(thestate);
    mu_request_pre.to_state(thestate);
    mu_flag.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_state.value(from.mu_state.value());
    mu_owner.value(from.mu_owner.value());
    mu_sharers = from.mu_sharers;
    mu_val.value(from.mu_val.value());
    mu_requester.value(from.mu_requester.value());
    mu_request_type.value(from.mu_request_type.value());
    mu_request_pre.value(from.mu_request_pre.value());
    mu_flag.value(from.mu_flag.value());
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_owner.set_self_2(name, ".owner", os + 8 );
  mu_sharers.set_self_2(name, ".sharers", os + 16 );
  mu_val.set_self_2(name, ".val", os + 112 );
  mu_requester.set_self_2(name, ".requester", os + 120 );
  mu_request_type.set_self_2(name, ".request_type", os + 128 );
  mu_request_pre.set_self_2(name, ".request_pre", os + 136 );
  mu_flag.set_self_2(name, ".flag", os + 144 );
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_11: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_11& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_11& val)
  {
    if (val.defined())
      return ( s << mu_1__type_11::values[ int(val) - 84] );
    else return ( s << "Undefined" );
  };

  mu_1__type_11 (char *name, int os): mu__byte(84, 110, 5, name, os) {};
  mu_1__type_11 (void): mu__byte(84, 110, 5) {};
  mu_1__type_11 (int val): mu__byte(84, 110, 5, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -84]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -84] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_11::values[] = {"P_M","P_E","P_S","P_I","PT_MI_GP","PT_IM_A","PT_IM_D","PT_IM_AD","PT_MI_A","PT_II_GOI","PT_II_WP","PT_II_GO","PT_IE_GP","PT_EI_GOI","PT_EI_GP","PT_SE_GOE","PT_IS_A","PT_IS_D","PT_IS_AD","PT_SI_GOI","PT_SI_GP","PT_IE_D","PT_II_GP","PT_SM_AD","PT_SM_A","PT_SM_D","PT_SM_GOE",NULL };

/*** end of enum declaration ***/
mu_1__type_11 mu_1__type_11_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_11 mu_state;
  mu_1_Value mu_val;
  mu_1_Address mu_addr;
  mu_1_Value mu_mem_write_val;
  mu_1_ProcState ( char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_addr, b.mu_addr);
    if (w!=0) return w;
    w = CompareWeight(a.mu_mem_write_val, b.mu_mem_write_val);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_addr, b.mu_addr);
    if (w!=0) return w;
    w = Compare(a.mu_mem_write_val, b.mu_mem_write_val);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_val.MultisetSort();
    mu_addr.MultisetSort();
    mu_mem_write_val.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_val.print_statistic();
    mu_addr.print_statistic();
    mu_mem_write_val.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_val.clear();
    mu_addr.clear();
    mu_mem_write_val.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_val.undefine();
    mu_addr.undefine();
    mu_mem_write_val.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_val.reset();
    mu_addr.reset();
    mu_mem_write_val.reset();
 };
  void print() {
    mu_state.print();
    mu_val.print();
    mu_addr.print();
    mu_mem_write_val.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_addr.print_diff(prevstate);
    mu_mem_write_val.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_val.to_state(thestate);
    mu_addr.to_state(thestate);
    mu_mem_write_val.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_state.value(from.mu_state.value());
    mu_val.value(from.mu_val.value());
    mu_addr.value(from.mu_addr.value());
    mu_mem_write_val.value(from.mu_mem_write_val.value());
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_val.set_self_2(name, ".val", os + 8 );
  mu_addr.set_self_2(name, ".addr", os + 16 );
  mu_mem_write_val.set_self_2(name, ".mem_write_val", os + 24 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_12
{
 public:
  mu_1_HomeState array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_12 (char *n, int os) { set_self(n, os); };
  mu_1__type_12 ( void ) {};
  virtual ~mu_1__type_12 ();
  mu_1_HomeState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 7 ) && ( index <= 8 ) )
      return array[ index - 7 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 7 ];
#endif
  };
  mu_1__type_12& operator= (const mu_1__type_12& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_12::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_12::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_12::set_self( char *n, int os)
  {
    int i=0;
    name = n;

array[i].set_self_ar(n,"Home0", i * 152 + os);i++;
array[i].set_self_ar(n,"Home1", i * 152 + os);i++;
  }
mu_1__type_12::~mu_1__type_12()
{
}
/*** end array declaration ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1__type_13
{
 public:
  mu_1_ProcState array[ 6 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_13 (char *n, int os) { set_self(n, os); };
  mu_1__type_13 ( void ) {};
  virtual ~mu_1__type_13 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 6 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Proc is internally represented from 6 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_13& operator= (const mu_1__type_13& from)
  {
    for (int i = 0; i < 6; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_13& a, mu_1__type_13& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_13& a, mu_1__type_13& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<6; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<6; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 6; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 6; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 6; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 6; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 6; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 6; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_13::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_13::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_13::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Proc_1", i * 32 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 32 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 32 + os);i++;
array[i].set_self_ar(n,"Proc_4", i * 32 + os);i++;
array[i].set_self_ar(n,"Proc_5", i * 32 + os);i++;
array[i].set_self_ar(n,"Proc_6", i * 32 + os);i++;
}
mu_1__type_13::~mu_1__type_13()
{
}
/*** end array declaration ***/
mu_1__type_13 mu_1__type_13_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_14_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_14_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_14_id () : mu__byte(0,12,0) {};
  mu_1__type_14_id (int val) : mu__byte(0,12,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_14
{
 public:
  mu_1_Message array[ 13 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 13 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_14 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_14 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_14 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 12) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_14& operator= (const mu_1__type_14& from)
  {
    for (int i = 0; i < 13; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_14& a, mu_1__type_14& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_14& a, mu_1__type_14& b)
  {
    int w;
    for (int i=0; i<13; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 13; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 13; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 13; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 13; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 13; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 13; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_14_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 13; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 13; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 13) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 13; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_14_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 13; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 13; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 13; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_14::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_14::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_14::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 13; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 120 + os);
  k = os + i * 120;
  for(i = 0; i < 13; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_14::~mu_1__type_14()
{
}
/*** end multiset declaration ***/
mu_1__type_14 mu_1__type_14_undefined_var;

class mu_1__type_15
{
 public:
  mu_1__type_14 array[ 8 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_15 (char *n, int os) { set_self(n, os); };
  mu_1__type_15 ( void ) {};
  virtual ~mu_1__type_15 ();
  mu_1__type_14& operator[] (int index) /* const */
  {
    if ( ( index >= 7 ) && ( index <= 8 ) )
      return array[ index - (7) ];
    if ( ( index >= 1 ) && ( index <= 6 ) )
      return array[ index - (-1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_15& operator= (const mu_1__type_15& from)
  {
    for (int i = 0; i < 8; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_15& a, mu_1__type_15& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_15& a, mu_1__type_15& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 8; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 8; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_15::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_15::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_15::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home0", i * 1664 + os);i++;
array[i].set_self_ar(n,"Home1", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_4", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_5", i * 1664 + os);i++;
array[i].set_self_ar(n,"Proc_6", i * 1664 + os);i++;
}
mu_1__type_15::~mu_1__type_15()
{
}
/*** end array declaration ***/
mu_1__type_15 mu_1__type_15_undefined_var;

class mu_1__type_16
{
 public:
  mu_1_Message array[ 6 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_16 (char *n, int os) { set_self(n, os); };
  mu_1__type_16 ( void ) {};
  virtual ~mu_1__type_16 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 5 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_16& operator= (const mu_1__type_16& from)
  {
    for (int i = 0; i < 6; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_16& a, mu_1__type_16& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_16& a, mu_1__type_16& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<6; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<6; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 6; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 6; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 6; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 6; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 6; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 6; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_16::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_16::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_16::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 6; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 120 + os);
    delete[] s;
  }
};
mu_1__type_16::~mu_1__type_16()
{
}
/*** end array declaration ***/
mu_1__type_16 mu_1__type_16_undefined_var;

class mu_1__type_17
{
 public:
  mu_1__type_16 array[ 8 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_17 (char *n, int os) { set_self(n, os); };
  mu_1__type_17 ( void ) {};
  virtual ~mu_1__type_17 ();
  mu_1__type_16& operator[] (int index) /* const */
  {
    if ( ( index >= 7 ) && ( index <= 8 ) )
      return array[ index - (7) ];
    if ( ( index >= 1 ) && ( index <= 6 ) )
      return array[ index - (-1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_17& operator= (const mu_1__type_17& from)
  {
    for (int i = 0; i < 8; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_17& a, mu_1__type_17& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_17& a, mu_1__type_17& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 8; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 8; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_17::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_17::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_17::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home0", i * 720 + os);i++;
array[i].set_self_ar(n,"Home1", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_4", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_5", i * 720 + os);i++;
array[i].set_self_ar(n,"Proc_6", i * 720 + os);i++;
}
mu_1__type_17::~mu_1__type_17()
{
}
/*** end array declaration ***/
mu_1__type_17 mu_1__type_17_undefined_var;

class mu_1__type_18: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_18& val) { return mu__byte::operator=((int) val); };
  mu_1__type_18 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_18 (void): mu__byte(0, 1, 2) {};
  mu_1__type_18 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_18 mu_1__type_18_undefined_var;

class mu_1__type_19: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_19& val) { return mu__byte::operator=((int) val); };
  mu_1__type_19 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_19 (void): mu__byte(0, 1, 2) {};
  mu_1__type_19 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_19 mu_1__type_19_undefined_var;

class mu_1__type_20: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_20& val) { return mu__byte::operator=((int) val); };
  mu_1__type_20 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_20 (void): mu__byte(0, 1, 2) {};
  mu_1__type_20 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_20 mu_1__type_20_undefined_var;

class mu_1__type_21: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_21& val) { return mu__byte::operator=((int) val); };
  mu_1__type_21 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_21 (void): mu__byte(0, 1, 2) {};
  mu_1__type_21 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_21 mu_1__type_21_undefined_var;

class mu_1__type_22: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_22& val) { return mu__byte::operator=((int) val); };
  mu_1__type_22 (char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_22 (void): mu__byte(0, 1, 2) {};
  mu_1__type_22 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_22 mu_1__type_22_undefined_var;

class mu_1__type_23: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_23& val) { return mu__byte::operator=((int) val); };
  mu_1__type_23 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_23 (void): mu__byte(0, 3, 3) {};
  mu_1__type_23 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_23 mu_1__type_23_undefined_var;

class mu_1__type_24: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_24& val) { return mu__byte::operator=((int) val); };
  mu_1__type_24 (char *name, int os): mu__byte(0, 6, 3, name, os) {};
  mu_1__type_24 (void): mu__byte(0, 6, 3) {};
  mu_1__type_24 (int val): mu__byte(0, 6, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_24 mu_1__type_24_undefined_var;

const int mu_ProcCount = 6;
const int mu_HomeCount = 2;
const int mu_ValueCount = 2;
const int mu_AddrCount = 2;
const int mu_D2H_REQ = 0;
const int mu_H2D_REQ = 1;
const int mu_D2H_DATA = 2;
const int mu_D2H_RSP = 3;
const int mu_H2D_DATA = 4;
const int mu_H2D_RSP = 5;
const int mu_QMax = 6;
const int mu_NumVCs = 6;
const int mu_NetMax = 13;
const int mu_MaxUQID = 1;
const int mu_Proc_1 = 1;
const int mu_Proc_2 = 2;
const int mu_Proc_3 = 3;
const int mu_Proc_4 = 4;
const int mu_Proc_5 = 5;
const int mu_Proc_6 = 6;
const int mu_Home0 = 7;
const int mu_Home1 = 8;
const int mu_UQIDType_1 = 9;
const int mu_M = 10;
const int mu_E = 11;
const int mu_S = 12;
const int mu_I = 13;
const int mu_RdCurr = 14;
const int mu_RdOwn = 15;
const int mu_RdShared = 16;
const int mu_RdAny = 17;
const int mu_RdOwnNoData = 18;
const int mu_ItoMWr = 19;
const int mu_WrCur = 20;
const int mu_CLFlush = 21;
const int mu_CleanEvict = 22;
const int mu_DirtyEvict = 23;
const int mu_CleanEvictNoData = 24;
const int mu_WrInv = 25;
const int mu_CacheFlushed = 26;
const int mu_RspIHitI = 27;
const int mu_RspVHitV = 28;
const int mu_RspIHitSE = 29;
const int mu_RspSHitSE = 30;
const int mu_RspSFwdM = 31;
const int mu_RspIFwdM = 32;
const int mu_RspVFwdV = 33;
const int mu_WritePull = 34;
const int mu_GO = 35;
const int mu_GO_WritePull = 36;
const int mu_ExtCmp = 37;
const int mu_GO_WritePull_Drop = 38;
const int mu_Reserved = 39;
const int mu_Fast_GO_WritePull = 40;
const int mu_GO_ERR_WritePull = 41;
const int mu_SnpData = 42;
const int mu_SnpInv = 43;
const int mu_SnpCur = 44;
const int mu_Data = 45;
const int mu_H_M = 46;
const int mu_H_E = 47;
const int mu_H_S = 48;
const int mu_H_I = 49;
const int mu_HT_SI_A = 50;
const int mu_HT_SE_A = 51;
const int mu_HT_II_D = 52;
const int mu_HT_II_AD = 53;
const int mu_HT_IS_A = 54;
const int mu_HT_MM_AD = 55;
const int mu_HT_MM_A = 56;
const int mu_HT_MM_D = 57;
const int mu_HT_MI_AD = 58;
const int mu_HT_MI_D = 59;
const int mu_HT_MI_A = 60;
const int mu_HT_MI_AD1 = 61;
const int mu_HT_MI_A1 = 62;
const int mu_HT_MI_D1 = 63;
const int mu_HT_ME_AD = 64;
const int mu_HT_ME_A = 65;
const int mu_HT_ME_D = 66;
const int mu_HT_EI_AD = 67;
const int mu_HT_EI_A = 68;
const int mu_HT_EI_D = 69;
const int mu_HT_EE_AD = 70;
const int mu_HT_EE_A = 71;
const int mu_HT_EE_D = 72;
const int mu_HT_ES_AD = 73;
const int mu_HT_ES_A = 74;
const int mu_HT_ES_D = 75;
const int mu_HT_MS_AD = 76;
const int mu_HT_MS_D = 77;
const int mu_HT_MS_A = 78;
const int mu_flag_EM_D = 79;
const int mu_flag_EI_D = 80;
const int mu_flag_EE_D = 81;
const int mu_flag_ES_D = 82;
const int mu_flag_SI_A = 83;
const int mu_P_M = 84;
const int mu_P_E = 85;
const int mu_P_S = 86;
const int mu_P_I = 87;
const int mu_PT_MI_GP = 88;
const int mu_PT_IM_A = 89;
const int mu_PT_IM_D = 90;
const int mu_PT_IM_AD = 91;
const int mu_PT_MI_A = 92;
const int mu_PT_II_GOI = 93;
const int mu_PT_II_WP = 94;
const int mu_PT_II_GO = 95;
const int mu_PT_IE_GP = 96;
const int mu_PT_EI_GOI = 97;
const int mu_PT_EI_GP = 98;
const int mu_PT_SE_GOE = 99;
const int mu_PT_IS_A = 100;
const int mu_PT_IS_D = 101;
const int mu_PT_IS_AD = 102;
const int mu_PT_SI_GOI = 103;
const int mu_PT_SI_GP = 104;
const int mu_PT_IE_D = 105;
const int mu_PT_II_GP = 106;
const int mu_PT_SM_AD = 107;
const int mu_PT_SM_A = 108;
const int mu_PT_SM_D = 109;
const int mu_PT_SM_GOE = 110;
/*** Variable declaration ***/
mu_1__type_12 mu_HomeNodes("HomeNodes",0);

/*** Variable declaration ***/
mu_1__type_13 mu_Procs("Procs",304);

/*** Variable declaration ***/
mu_1__type_15 mu_Net("Net",496);

/*** Variable declaration ***/
mu_1__type_17 mu_InBox("InBox",13808);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",19568);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite0("LastWrite0",19576);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite1("LastWrite1",19584);

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dst, const mu_1_Node& mu_src, const mu_1_VCType& mu_vc, const mu_1_Value& mu_val, const mu_1_Address& mu_addr, const mu_1_UQIDType& mu_cqid, const mu_1_UQIDType& mu_uqid, const mu_1__type_18& mu_nt, const mu_1__type_19& mu_chunkvalid, const mu_1__type_20& mu_poison, const mu_1__type_21& mu_bogus, const mu_1__type_22& mu_go_err, const mu_1_RspData& mu_rspdata, const mu_1__type_23& mu_rsp_pre)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr25 = 0;
  {
  mu_1__type_14_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net[mu_dst].valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr25++;
        }
      if (mu_i == 13-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr25) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
mu_msg.mu_valid = 1;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_vc.isundefined())
  mu_msg.mu_vc.undefine();
else
  mu_msg.mu_vc = mu_vc;
if (mu_val.isundefined())
  mu_msg.mu_val.undefine();
else
  mu_msg.mu_val = mu_val;
if (mu_addr.isundefined())
  mu_msg.mu_addr.undefine();
else
  mu_msg.mu_addr = mu_addr;
if (mu_cqid.isundefined())
  mu_msg.mu_cqid.undefine();
else
  mu_msg.mu_cqid = mu_cqid;
if (mu_uqid.isundefined())
  mu_msg.mu_uqid.undefine();
else
  mu_msg.mu_uqid = mu_uqid;
if (mu_nt.isundefined())
  mu_msg.mu_nt.undefine();
else
  mu_msg.mu_nt = mu_nt;
if (mu_chunkvalid.isundefined())
  mu_msg.mu_chunkvalid.undefine();
else
  mu_msg.mu_chunkvalid = mu_chunkvalid;
if (mu_poison.isundefined())
  mu_msg.mu_poison.undefine();
else
  mu_msg.mu_poison = mu_poison;
if (mu_bogus.isundefined())
  mu_msg.mu_bogus.undefine();
else
  mu_msg.mu_bogus = mu_bogus;
if (mu_go_err.isundefined())
  mu_msg.mu_go_err.undefine();
else
  mu_msg.mu_go_err = mu_go_err;
if (mu_rspdata.isundefined())
  mu_msg.mu_rspdata.undefine();
else
  mu_msg.mu_rspdata = mu_rspdata;
if (mu_rsp_pre.isundefined())
  mu_msg.mu_rsp_pre.undefine();
else
  mu_msg.mu_rsp_pre = mu_rsp_pre;
mu_Net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_AddToSharersList(const mu_1_Node& mu_n, const mu_1_Home& mu_h)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr26 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNodes[mu_h].mu_sharers[mu_i]) == (mu_n) ) mu__intexpr26++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr26) == (0) )
{
mu_HomeNodes[mu_h].mu_sharers.multisetadd(mu_n);
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_IsSharer(const mu_1_Node& mu_n,const mu_1_Home& mu_h)
{
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr27 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNodes[mu_h].mu_sharers[mu_i]) == (mu_n) ) mu__intexpr27++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
return (mu__intexpr27) > (0);
  Error.Error("The end of function IsSharer reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_IsSharerListEmpty(const mu_1_Home& mu_h)
{
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr28 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr28++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
return (mu__intexpr28) == (0);
  Error.Error("The end of function IsSharerListEmpty reached without returning values.");
};
/*** end function declaration ***/

void mu_RemoveFromSharersList(const mu_1_Node& mu_n, const mu_1_Home& mu_h)
{
/*** end multisetremove 0 declaration ***/
  mu_1__type_8_id mu__idexpr29;
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNodes[mu_h].mu_sharers[mu_i]) == (mu_n) ) { mu__idexpr29 = mu_i; mu_HomeNodes[mu_h].mu_sharers.multisetremove(mu__idexpr29); };
        }
      if (mu_i == 6-1) break;
    }
/*** end multisetremove 0 declaration ***/
};
/*** end procedure declaration ***/

void mu_SendInvReqToSharers(const mu_1_Node& mu_rqst, const mu_1_Home& mu_h, mu_1_Message& mu_msg)
{
{
for(int mu_n = 1; mu_n <= 8; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 6 ) )|| ( ( mu_n >= 7 ) && ( mu_n <= 8 ) )) {
bool mu__boolexpr30;
  if (!((mu_n>=1 && mu_n<=6))) mu__boolexpr30 = FALSE ;
  else {
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr31 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNodes[mu_h].mu_sharers[mu_i]) == (mu_n) ) mu__intexpr31++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
  mu__boolexpr30 = ((mu__intexpr31) != (0)) ; 
}
if ( mu__boolexpr30 )
{
mu_RemoveFromSharersList ( mu_n, mu_h );
if ( (mu_n) != (mu_rqst) )
{
if ( (mu_h) == (mu_Home0) )
{
mu_Send ( mu_SnpInv, mu_n, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, 0, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_SnpInv, mu_n, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, 1, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
}
}
};
};
};
/*** end procedure declaration ***/

void mu_HomeReceive(mu_1_Message& mu_msg, const mu_1_Home& mu_h)
{
/*** Variable declaration ***/
mu_1__type_24 mu_cnt("cnt",0);

{
  mu_1__type_7& mu_hs = mu_HomeNodes[mu_h].mu_state;
{
  mu_1_Value& mu_hv = mu_HomeNodes[mu_h].mu_val;
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr32 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr32++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
mu_cnt = mu__intexpr32;
mu_msg_processed = mu_true;
switch ((int) mu_HomeNodes[mu_h].mu_state) {
case mu_H_I:
switch ((int) mu_msg.mu_mtype) {
case mu_RdCurr:
mu_hs = mu_H_I;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_CLFlush:
mu_hs = mu_H_I;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
case mu_ItoMWr:
mu_hs = mu_HT_II_AD;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
break;
case mu_RdShared:
if ( mu_IsSharerListEmpty( mu_h ) )
{
mu_hs = mu_H_M;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_M, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
}
else
{
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
}
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_hv, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdAny:
if ( mu_IsSharerListEmpty( mu_h ) )
{
mu_hs = mu_H_M;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_M, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
}
else
{
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
}
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_hv, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdOwnNoData:
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
break;
case mu_WrCur:
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_flag = mu_flag_EI_D;
mu_Send ( mu_GO_WritePull, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_II_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitI:
mu_hs = mu_HT_II_D;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_cqid, 1 );
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_II_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_H_I;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_hv, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_requester.undefine();
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_H_E:
if ( !(!(mu_HomeNodes[mu_h].mu_owner.isundefined())) ) Error.Error("Assertion failed: HomeNodes has no owner, but line is Exclusive");
if ( !((mu_cnt) == (0)) ) Error.Error("Assertion failed: HomeNodes has sharer, but line is Exclusive");
switch ((int) mu_msg.mu_mtype) {
case mu_RdCurr:
mu_hs = mu_HT_EE_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_Send ( mu_SnpCur, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdOwn:
mu_hs = mu_HT_EE_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdShared:
mu_hs = mu_HT_ES_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
mu_AddToSharersList ( mu_HomeNodes[mu_h].mu_owner, mu_h );
mu_HomeNodes[mu_h].mu_owner.undefine();
mu_Send ( mu_SnpData, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdAny:
mu_hs = mu_HT_ES_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
mu_AddToSharersList ( mu_HomeNodes[mu_h].mu_owner, mu_h );
mu_HomeNodes[mu_h].mu_owner.undefine();
mu_Send ( mu_SnpData, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdOwnNoData:
break;
case mu_ItoMWr:
mu_hs = mu_HT_EE_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_WrCur:
mu_hs = mu_HT_EE_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_CLFlush:
mu_hs = mu_HT_EI_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_HomeNodes[mu_h].mu_owner.undefine();
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_CleanEvict:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_cqid, 1 );
break;
case mu_DirtyEvict:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_cqid, 1 );
break;
case mu_CleanEvictNoData:
mu_hs = mu_H_I;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
case mu_WrInv:
mu_hs = mu_HT_EI_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_CacheFlushed:
mu_hs = mu_HT_EI_AD;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_request_pre = 1;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EI_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitSE:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_CLFlush:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_WrInv:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_CacheFlushed:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_CLFlush:
mu_hs = mu_HT_EI_D;
break;
case mu_WrInv:
mu_hs = mu_HT_EI_D;
break;
case mu_CacheFlushed:
mu_hs = mu_HT_EI_D;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_Data:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_CLFlush:
mu_hs = mu_HT_EI_A;
mu_hv = mu_msg.mu_val;
break;
case mu_WrInv:
mu_hs = mu_HT_EI_A;
mu_hv = mu_msg.mu_val;
break;
case mu_CacheFlushed:
mu_hs = mu_HT_EI_A;
mu_hv = mu_msg.mu_val;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_CLFlush:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_WrInv:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_CacheFlushed:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EI_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_CLFlush:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_WrInv:
if ( (mu_HomeNodes[mu_h].mu_request_pre) == (1) )
{
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
}
else
{
mu_hs = mu_H_I;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
}
break;
case mu_CacheFlushed:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
case mu_ItoMWr:
mu_hs = mu_H_I;
mu_hv = mu_msg.mu_val;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_WrCur:
mu_hs = mu_H_I;
mu_hv = mu_msg.mu_val;
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EE_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitSE:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdCurr:
mu_hs = mu_H_E;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdOwn:
mu_hs = mu_H_E;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_ItoMWr:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_WrCur:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdCurr:
mu_hs = mu_HT_EE_D;
break;
case mu_RdOwn:
mu_hs = mu_HT_EE_D;
break;
case mu_ItoMWr:
mu_hs = mu_HT_EE_D;
break;
case mu_WrCur:
mu_hs = mu_HT_EE_D;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_Data:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdCurr:
mu_hs = mu_HT_EE_A;
mu_hv = mu_msg.mu_val;
break;
case mu_RdOwn:
mu_hs = mu_HT_EE_A;
mu_hv = mu_msg.mu_val;
break;
case mu_ItoMWr:
mu_hs = mu_HT_EE_A;
mu_hv = mu_msg.mu_val;
break;
case mu_WrCur:
mu_hs = mu_HT_EE_A;
mu_hv = mu_msg.mu_val;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EE_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdCurr:
mu_hs = mu_H_E;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdOwn:
mu_hs = mu_H_E;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_ItoMWr:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_WrCur:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_EE_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdCurr:
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_val = mu_msg.mu_val;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdOwn:
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_val = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_ItoMWr:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_HomeNodes[mu_h].mu_val = mu_msg.mu_val;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_WrCur:
mu_hs = mu_HT_EI_D;
mu_HomeNodes[mu_h].mu_request_pre = 0;
mu_HomeNodes[mu_h].mu_val = mu_msg.mu_val;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ES_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitSE:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdShared:
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdAny:
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdShared:
mu_hs = mu_HT_ES_D;
break;
case mu_RdAny:
mu_hs = mu_HT_ES_D;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_Data:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdShared:
mu_hs = mu_HT_ES_A;
mu_hv = mu_msg.mu_val;
break;
case mu_RdAny:
mu_hs = mu_HT_ES_A;
mu_hv = mu_msg.mu_val;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ES_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdShared:
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdAny:
mu_hs = mu_H_S;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ES_D:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdShared:
mu_hs = mu_H_S;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
case mu_RdAny:
mu_hs = mu_H_S;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_pre.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_H_S:
if ( !((mu_HomeNodes[mu_h].mu_owner.isundefined()) == (mu_true)) ) Error.Error("Assertion failed: HomeNodes has owner, but line is Shared");
if ( !((mu_cnt) != (0)) ) Error.Error("Assertion failed: HomeNodes has no sharer, but line is Shared");
switch ((int) mu_msg.mu_mtype) {
case mu_RdShared:
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
break;
case mu_RdAny:
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
break;
case mu_RdCurr:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdOwnNoData:
if ( mu_IsSharer( mu_msg.mu_src, mu_h ) )
{
if ( (mu_cnt) == (1) )
{
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
}
else
{
mu_SendInvReqToSharers ( mu_msg.mu_src, mu_h, mu_msg );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
}
}
else
{
if ( (mu_cnt) == (0) )
{
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_hs = mu_H_E;
}
else
{
mu_SendInvReqToSharers ( mu_msg.mu_src, mu_h, mu_msg );
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
}
}
break;
case mu_RdOwn:
if ( mu_IsSharer( mu_msg.mu_src, mu_h ) )
{
if ( (mu_cnt) == (1) )
{
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_hs = mu_H_E;
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
}
else
{
mu_SendInvReqToSharers ( mu_msg.mu_src, mu_h, mu_msg );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
}
}
else
{
if ( (mu_cnt) == (0) )
{
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_hs = mu_H_E;
}
else
{
mu_SendInvReqToSharers ( mu_msg.mu_src, mu_h, mu_msg );
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
}
}
break;
case mu_WrCur:
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_flag = mu_flag_EI_D;
mu_SendInvReqToSharers ( mu_HomeNodes[mu_h].mu_owner, mu_h, mu_msg );
break;
case mu_ItoMWr:
mu_hs = mu_HT_SE_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_HomeNodes[mu_h].mu_flag = mu_flag_EI_D;
mu_SendInvReqToSharers ( mu_HomeNodes[mu_h].mu_owner, mu_h, mu_msg );
break;
case mu_CleanEvictNoData:
if ( (mu_cnt) == (1) )
{
mu_hs = mu_H_I;
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
}
else
{
mu_Send ( mu_GO, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
mu_RemoveFromSharersList ( mu_msg.mu_src, mu_h );
}
break;
case mu_CLFlush:
mu_hs = mu_HT_SI_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_SendInvReqToSharers ( mu_HomeNodes[mu_h].mu_owner, mu_h, mu_msg );
break;
case mu_WrInv:
mu_hs = mu_HT_SI_A;
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
mu_SendInvReqToSharers ( mu_HomeNodes[mu_h].mu_owner, mu_h, mu_msg );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_SI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitSE:
if ( (mu_cnt) == (0) )
{
if ( (mu_HomeNodes[mu_h].mu_request_type) == (mu_WrInv) )
{
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
}
else
{
mu_hs = mu_H_I;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
}
}
break;
case mu_Data:
bool mu__boolexpr33;
  if (!((mu_HomeNodes[mu_h].mu_flag) == (mu_flag_SI_A))) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_msg.mu_src) == (mu_HomeNodes[mu_h].mu_requester)) ; 
}
if ( mu__boolexpr33 )
{
mu_hs = mu_H_I;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_HomeNodes[mu_h].mu_requester;
mu_HomeNodes[mu_h].mu_val = mu_msg.mu_val;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
}
else
{
mu_msg_processed = mu_false;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_SE_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIHitSE:
if ( !((mu_HomeNodes[mu_h].mu_request_type.isundefined()) == (mu_false)) ) Error.Error("Assertion failed: In HT_SE_A, request_type should be defined");
if ( (mu_cnt) == (0) )
{
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_RdOwn:
mu_hs = mu_H_E;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_owner = mu_HomeNodes[mu_h].mu_requester;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdOwnNoData:
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_HomeNodes[mu_h].mu_requester;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_WrCur:
if ( !((mu_HomeNodes[mu_h].mu_flag) == (mu_flag_ES_D)) ) Error.Error("Assertion failed: flag_ES_D for ItoMWr");
mu_hs = mu_H_E;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_HomeNodes[mu_h].mu_requester;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_ItoMWr:
if ( !((mu_HomeNodes[mu_h].mu_flag) == (mu_flag_EI_D)) ) Error.Error("Assertion failed: flag_EI_D for ItoMWr");
mu_hs = mu_H_E;
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
mu_HomeNodes[mu_h].mu_owner = mu_HomeNodes[mu_h].mu_requester;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
}
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_H_M:
if ( !((mu_HomeNodes[mu_h].mu_owner.isundefined()) == (mu_false)) ) Error.Error("Assertion failed: HomeNodes has no owner, but line is Modified");
mu_HomeNodes[mu_h].mu_requester = mu_msg.mu_src;
mu_HomeNodes[mu_h].mu_request_type = mu_msg.mu_mtype;
switch ((int) mu_msg.mu_mtype) {
case mu_RdCurr:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request RdCurr");
mu_hs = mu_HT_MM_AD;
mu_Send ( mu_SnpCur, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_CLFlush:
mu_hs = mu_HT_MI_AD;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_owner.undefine();
break;
case mu_DirtyEvict:
if ( !((mu_msg.mu_src) == (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: only owner can request DirtyEvict");
mu_hs = mu_HT_MI_D;
mu_Send ( mu_GO_WritePull, mu_msg.mu_src, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_cqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_cqid, 1 );
mu_HomeNodes[mu_h].mu_owner.undefine();
break;
case mu_WrInv:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request WrInv");
mu_hs = mu_HT_MI_AD1;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_owner.undefine();
break;
case mu_ItoMWr:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request ItoMWr");
mu_hs = mu_HT_MI_AD1;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
break;
case mu_RdOwn:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request RdOwn");
mu_hs = mu_HT_ME_AD;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_owner = mu_msg.mu_src;
break;
case mu_WrCur:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request WrCur");
mu_hs = mu_HT_MI_AD1;
mu_Send ( mu_SnpInv, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RdShared:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request RdShared");
mu_hs = mu_HT_MS_AD;
mu_Send ( mu_SnpData, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
mu_HomeNodes[mu_h].mu_owner.undefine();
break;
case mu_RdAny:
if ( !((mu_msg.mu_src) != (mu_HomeNodes[mu_h].mu_owner)) ) Error.Error("Assertion failed: owner should not request RdAny");
mu_hs = mu_HT_MS_AD;
mu_Send ( mu_SnpData, mu_HomeNodes[mu_h].mu_owner, (int)mu_h, mu_H2D_REQ, mu_1_Value_undefined_var, mu_msg.mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_AddToSharersList ( mu_msg.mu_src, mu_h );
mu_HomeNodes[mu_h].mu_owner.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_MM_A;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RspVFwdV:
mu_hs = mu_HT_MM_D;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspVFwdV:
mu_hs = mu_H_M;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MM_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_H_M;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_AD1:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_MI_A1;
mu_hv = mu_msg.mu_val;
break;
case mu_RspIFwdM:
mu_hs = mu_HT_MI_D1;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_A1:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
mu_hs = mu_HT_MI_D;
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_WrInv:
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_ItoMWr:
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_WrCur:
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledState (  );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_D1:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_MI_D;
mu_hv = mu_msg.mu_val;
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_WrInv:
mu_Send ( mu_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_ItoMWr:
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
case mu_WrCur:
mu_Send ( mu_GO_WritePull, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_msg.mu_uqid, 1 );
break;
default:
mu_ErrorUnhandledState (  );
break;
}
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_AD:
if ( !((mu_HomeNodes[mu_h].mu_request_type) == (mu_CLFlush)) ) Error.Error("Assertion failed: only CLFlush should be here");
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_MI_A;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
case mu_RspIFwdM:
mu_hs = mu_HT_MI_D;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
mu_hs = mu_H_I;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MI_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_H_I;
mu_hv = mu_msg.mu_val;
switch ((int) mu_HomeNodes[mu_h].mu_request_type) {
case mu_DirtyEvict:
break;
case mu_WrInv:
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
case mu_CLFlush:
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_I, 1 );
break;
default:
mu_ErrorUnhandledState (  );
break;
}
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ME_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_ME_A;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RspIFwdM:
mu_hs = mu_HT_ME_D;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ME_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
mu_hs = mu_H_M;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_ME_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_H_M;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_E, 1 );
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MS_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_HT_MS_A;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_RspIFwdM:
mu_hs = mu_HT_MS_D;
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MS_A:
switch ((int) mu_msg.mu_mtype) {
case mu_RspIFwdM:
mu_hs = mu_H_S;
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
case mu_HT_MS_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_hs = mu_H_S;
mu_hv = mu_msg.mu_val;
mu_Send ( mu_Data, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_DATA, mu_HomeNodes[mu_h].mu_val, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, 0, 0, mu_1__type_21_undefined_var, 0, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_GO, mu_HomeNodes[mu_h].mu_requester, (int)mu_h, mu_H2D_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_msg.mu_uqid, mu_1_UQIDType_undefined_var, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, (int)mu_S, 1 );
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
break;
case mu_RdCurr:
mu_msg_processed = mu_false;
break;
case mu_RdOwn:
mu_msg_processed = mu_false;
break;
case mu_RdShared:
mu_msg_processed = mu_false;
break;
case mu_RdAny:
mu_msg_processed = mu_false;
break;
case mu_RdOwnNoData:
mu_msg_processed = mu_false;
break;
case mu_ItoMWr:
mu_msg_processed = mu_false;
break;
case mu_WrCur:
mu_msg_processed = mu_false;
break;
case mu_CLFlush:
mu_msg_processed = mu_false;
break;
case mu_CleanEvict:
mu_msg_processed = mu_false;
break;
case mu_DirtyEvict:
mu_msg_processed = mu_false;
break;
case mu_CleanEvictNoData:
mu_msg_processed = mu_false;
break;
case mu_WrInv:
mu_msg_processed = mu_false;
break;
case mu_CacheFlushed:
mu_msg_processed = mu_false;
break;
case mu_RspIHitI:
mu_msg_processed = mu_false;
break;
case mu_RspVHitV:
mu_msg_processed = mu_false;
break;
case mu_RspIHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSHitSE:
mu_msg_processed = mu_false;
break;
case mu_RspSFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspIFwdM:
mu_msg_processed = mu_false;
break;
case mu_RspVFwdV:
mu_msg_processed = mu_false;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_h );
break;
}
break;
}
}
}
};
/*** end procedure declaration ***/

void mu_ProcReceive(mu_1_Message& mu_msg, const mu_1_Proc& mu_p)
{
mu_msg_processed = mu_true;
{
  mu_1__type_11& mu_ps = mu_Procs[mu_p].mu_state;
{
  mu_1_Value& mu_pv = mu_Procs[mu_p].mu_val;
{
  mu_1_Address& mu_paddr = mu_Procs[mu_p].mu_addr;
switch ((int) mu_ps) {
case mu_P_I:
switch ((int) mu_msg.mu_mtype) {
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IS_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_S) )
{
mu_ps = mu_PT_IS_D;
}
else
{
if ( (mu_msg.mu_rspdata) == (mu_E) )
{
mu_ps = mu_PT_IE_D;
}
else
{
mu_msg_processed = mu_false;
}
}
break;
case mu_Data:
mu_pv = mu_msg.mu_val;
mu_ps = mu_PT_IS_A;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IS_A:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_S) )
{
mu_ps = mu_P_S;
}
else
{
if ( (mu_msg.mu_rspdata) == (mu_E) )
{
mu_ps = mu_P_E;
}
else
{
mu_msg_processed = mu_false;
}
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IS_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_pv = mu_msg.mu_val;
mu_ps = mu_P_S;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_M) )
{
mu_ps = mu_PT_IM_D;
}
else
{
mu_msg_processed = mu_false;
}
break;
case mu_Data:
mu_pv = mu_msg.mu_val;
mu_ps = mu_PT_IM_A;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IM_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_pv = mu_msg.mu_val;
mu_ps = mu_P_M;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_M) )
{
mu_ps = mu_P_M;
}
else
{
mu_msg_processed = mu_false;
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_SI_GOI:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( !((mu_msg.mu_rspdata) == (mu_I)) ) Error.Error("Assertion failed: The GO received should be GO-I");
mu_ps = mu_P_I;
mu_paddr.undefine();
mu_pv.undefine();
break;
case mu_SnpInv:
mu_ps = mu_PT_II_GOI;
mu_Send ( mu_RspIHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_paddr.undefine();
mu_pv.undefine();
break;
case mu_SnpCur:
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, 0, 0, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpData:
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_II_GOI:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( !((mu_msg.mu_rspdata) == (mu_I)) ) Error.Error("Assertion failed: The GO received should be GO-I");
mu_ps = mu_P_I;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_II_WP:
switch ((int) mu_msg.mu_mtype) {
case mu_WritePull:
mu_ps = mu_PT_II_GO;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_Procs[mu_p].mu_mem_write_val, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, 0, 0, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Procs[mu_p].mu_mem_write_val.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_II_GO:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_I) )
{
mu_ps = mu_P_I;
}
else
{
mu_msg_processed = mu_false;
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_II_GP:
switch ((int) mu_msg.mu_mtype) {
case mu_GO_WritePull:
mu_ps = mu_P_I;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IE_GP:
switch ((int) mu_msg.mu_mtype) {
case mu_GO_WritePull:
mu_ps = mu_P_E;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_Procs[mu_p].mu_mem_write_val, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_cqid, mu_1__type_18_undefined_var, 0, 0, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Procs[mu_p].mu_mem_write_val.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_P_E:
switch ((int) mu_msg.mu_mtype) {
case mu_SnpCur:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspVFwdV, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpData:
mu_ps = mu_P_S;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpInv:
mu_ps = mu_P_I;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspIHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_EI_GOI:
switch ((int) mu_msg.mu_mtype) {
case mu_GO:
if ( (mu_msg.mu_rspdata) == (mu_I) )
{
mu_ps = mu_P_I;
mu_pv.undefine();
mu_paddr.undefine();
}
else
{
mu_msg_processed = mu_false;
}
break;
case mu_SnpCur:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspVFwdV, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpData:
mu_ps = mu_PT_SI_GOI;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpInv:
mu_ps = mu_PT_II_GOI;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspIHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_EI_GP:
switch ((int) mu_msg.mu_mtype) {
case mu_GO_WritePull:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_ps = mu_P_I;
mu_pv.undefine();
mu_paddr.undefine();
break;
case mu_SnpCur:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspVFwdV, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpData:
mu_ps = mu_PT_SI_GP;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpInv:
mu_ps = mu_PT_II_GP;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspIHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_MI_GP:
switch ((int) mu_msg.mu_mtype) {
case mu_GO_WritePull:
if ( !((mu_msg.mu_rspdata) == (mu_I)) ) Error.Error("Assertion failed: The GO received should be GO-I");
mu_ps = mu_P_I;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_Procs[mu_p].mu_addr, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_paddr.undefine();
mu_pv.undefine();
break;
case mu_SnpCur:
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspVFwdV, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpData:
mu_ps = mu_PT_SI_GP;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspSHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
case mu_SnpInv:
mu_ps = mu_PT_II_GP;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_p, mu_D2H_DATA, mu_pv, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, 0, 0, mu_1__type_20_undefined_var, 0, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RspIHitSE, mu_msg.mu_src, (int)mu_p, mu_D2H_RSP, mu_1_Value_undefined_var, mu_1_Address_undefined_var, mu_1_UQIDType_undefined_var, mu_msg.mu_uqid, mu_1__type_18_undefined_var, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
}
}
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_HomeNodes.clear();
  mu_Procs.clear();
  mu_Net.clear();
  mu_InBox.clear();
  mu_msg_processed.clear();
  mu_LastWrite0.clear();
  mu_LastWrite1.clear();
}
void world_class::undefine()
{
  mu_HomeNodes.undefine();
  mu_Procs.undefine();
  mu_Net.undefine();
  mu_InBox.undefine();
  mu_msg_processed.undefine();
  mu_LastWrite0.undefine();
  mu_LastWrite1.undefine();
}
void world_class::reset()
{
  mu_HomeNodes.reset();
  mu_Procs.reset();
  mu_Net.reset();
  mu_InBox.reset();
  mu_msg_processed.reset();
  mu_LastWrite0.reset();
  mu_LastWrite1.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNodes.print();
  mu_Procs.print();
  mu_Net.print();
  mu_InBox.print();
  mu_msg_processed.print();
  mu_LastWrite0.print();
  mu_LastWrite1.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNodes.print_statistic();
  mu_Procs.print_statistic();
  mu_Net.print_statistic();
  mu_InBox.print_statistic();
  mu_msg_processed.print_statistic();
  mu_LastWrite0.print_statistic();
  mu_LastWrite1.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_HomeNodes.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
    mu_InBox.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_LastWrite0.print_diff(prevstate);
    mu_LastWrite1.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_HomeNodes.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_Net.to_state( newstate );
  mu_InBox.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_LastWrite0.to_state( newstate );
  mu_LastWrite1.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 6) + 0);
    r = r / 6;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
    return tsprintf("receive-blocked-vc, vc:%s, n:%s", mu_vc.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 6) + 0);
    r = r / 6;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
  return !(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 6) + 0);
    r = r / 6;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
    while (what_rule < 48 )
      {
        if ( ( TRUE  ) ) {
              if (!(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined())) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    mu_vc.value((r % 6) + 0);
    r = r / 6;
    mu_n.unionassign(r % 8);
    r = r / 8;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 6) + 0);
    r = r / 6;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
if ( (mu_n>=7 && mu_n<=8) )
{
mu_HomeReceive ( mu_InBox[mu_n][mu_vc], (int)mu_n );
}
else
{
mu_ProcReceive ( mu_InBox[mu_n][mu_vc], (int)mu_n );
}
if ( mu_msg_processed )
{
mu_InBox[mu_n][mu_vc].undefine();
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_14_id mu_midx;
    mu_midx.value((r % 13) + 0);
    r = r / 13;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
    return tsprintf("receive-net, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_14_id mu_midx;
    mu_midx.value((r % 13) + 0);
    r = r / 13;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
  if (!mu_Net[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_14& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_16& mu_box = mu_InBox[mu_n];
  return mu_box[mu_msg.mu_vc].mu_mtype.isundefined();
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 48;
    static mu_1__type_14_id mu_midx;
    mu_midx.value((r % 13) + 0);
    r = r / 13;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
    while (what_rule < 152 && mu_midx.value()<13 )
      {
        if ( ( TRUE && mu_Net[mu_n].in(mu_midx) ) ) {
  mu_1__type_14& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_16& mu_box = mu_InBox[mu_n];
              if (mu_box[mu_msg.mu_vc].mu_mtype.isundefined()) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 48;
    mu_midx.value((r % 13) + 0);
    r = r / 13;
    mu_n.unionassign(r % 8);
    r = r / 8;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_14_id mu_midx;
    mu_midx.value((r % 13) + 0);
    r = r / 13;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 8);
    r = r / 8;
  mu_1__type_14& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_16& mu_box = mu_InBox[mu_n];
if ( (mu_n>=7 && mu_n<=8) )
{
mu_HomeReceive ( mu_msg, (int)mu_n );
}
else
{
mu_ProcReceive ( mu_msg, (int)mu_n );
}
if ( !(mu_msg_processed) )
{
mu_box[mu_msg.mu_vc] = mu_msg;
}
mu_chan.multisetremove(mu_midx);
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state E, store data, ad:%s, v:%s, n:%s", mu_ad.Name(), mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_E);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 152;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 206 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_E)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 9;
        }
        else
          what_rule += 9;
    r = what_rule - 152;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_P_M;
mu_p.mu_val = mu_v;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state M, send DirtyEvict, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_M);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 206;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 224 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_M)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 206;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_MI_GP;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_DirtyEvict, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_p.mu_val, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_DirtyEvict, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_p.mu_val, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
mu_p.mu_val.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send cache flush, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 224;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 242 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 224;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_II_GOI;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CacheFlushed, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CacheFlushed, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send CLFlush, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 242;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 260 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 242;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_II_GOI;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CLFlush, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CLFlush, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state S, send RdOwnNoData, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 260;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 278 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 260;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_SM_GOE;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdOwnNoData, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
mu_Send ( mu_RdOwnNoData, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state S, send RdOwnNoData, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 278;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 296 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 278;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_SM_AD;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdOwnNoData, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_RdOwnNoData, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state S, send CleanEvictNoData, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 296;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 314 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 296;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_SI_GOI;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CleanEvictNoData, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CleanEvictNoData, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state S, send CleanEvict, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 314;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 332 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 314;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_SI_GP;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CleanEvict, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CleanEvict, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send RdCurr, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 332;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 350 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 332;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_P_I;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdCurr, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_RdCurr, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send RdShared, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 350;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 368 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 350;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_IS_AD;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdShared, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_RdShared, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase12 ********************/
class RuleBase12
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send ItoMWr, ad:%s, id:%s, v:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 368;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 422 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 9;
        }
        else
          what_rule += 9;
    r = what_rule - 368;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_IE_GP;
mu_p.mu_mem_write_val = mu_v;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_ItoMWr, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_ItoMWr, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase13 ********************/
class RuleBase13
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send WrCur, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 422;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 440 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 422;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_IE_GP;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_WrCur, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_WrCur, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase14 ********************/
class RuleBase14
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state E, send CleanEvictNoData, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_E);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 440;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 458 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_E)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 440;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_EI_GOI;
mu_p.mu_val.undefine();
mu_p.mu_addr.undefine();
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CleanEvictNoData, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CleanEvictNoData, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase15 ********************/
class RuleBase15
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state E, send CleanEvict, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_E);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 458;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 476 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_E)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 458;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_EI_GP;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_CleanEvict, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_CleanEvict, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase16 ********************/
class RuleBase16
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send WrInv, ad:%s, id:%s, v:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 476;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 530 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 9;
        }
        else
          what_rule += 9;
    r = what_rule - 476;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_II_WP;
mu_p.mu_mem_write_val = mu_v;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_WrInv, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_WrInv, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase17 ********************/
class RuleBase17
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send RdAny, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 530;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 548 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 530;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_IM_AD;
mu_p.mu_addr = mu_ad;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdAny, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_RdAny, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase18 ********************/
class RuleBase18
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("device in state I, send RdOwn, ad:%s, id:%s, n:%s", mu_ad.Name(), mu_id.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 548;
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 566 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 548;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    mu_n.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Address mu_ad;
    mu_ad.value((r % 3) + 0);
    r = r / 3;
    static mu_1_UQIDType mu_id;
    mu_id.value((r % 1) + 9);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 6) + 1);
    r = r / 6;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_state = mu_PT_IM_AD;
mu_p.mu_addr = mu_ad;
if ( (mu_ad) == (0) )
{
mu_Send ( mu_RdOwn, (int)mu_Home0, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
else
{
mu_Send ( mu_RdOwn, (int)mu_Home1, (int)mu_n, mu_D2H_REQ, mu_1_Value_undefined_var, mu_ad, mu_id, mu_1_UQIDType_undefined_var, 0, mu_1__type_19_undefined_var, mu_1__type_20_undefined_var, mu_1__type_21_undefined_var, mu_1__type_22_undefined_var, mu_1_RspData_undefined_var, mu_1__type_23_undefined_var );
}
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
  RuleBase12 R12;
  RuleBase13 R13;
  RuleBase14 R14;
  RuleBase15 R15;
  RuleBase16 R16;
  RuleBase17 R17;
  RuleBase18 R18;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<48)
    { R0.NextRule(what_rule);
      if (what_rule<48) return; }
  if (what_rule>=48 && what_rule<152)
    { R1.NextRule(what_rule);
      if (what_rule<152) return; }
  if (what_rule>=152 && what_rule<206)
    { R2.NextRule(what_rule);
      if (what_rule<206) return; }
  if (what_rule>=206 && what_rule<224)
    { R3.NextRule(what_rule);
      if (what_rule<224) return; }
  if (what_rule>=224 && what_rule<242)
    { R4.NextRule(what_rule);
      if (what_rule<242) return; }
  if (what_rule>=242 && what_rule<260)
    { R5.NextRule(what_rule);
      if (what_rule<260) return; }
  if (what_rule>=260 && what_rule<278)
    { R6.NextRule(what_rule);
      if (what_rule<278) return; }
  if (what_rule>=278 && what_rule<296)
    { R7.NextRule(what_rule);
      if (what_rule<296) return; }
  if (what_rule>=296 && what_rule<314)
    { R8.NextRule(what_rule);
      if (what_rule<314) return; }
  if (what_rule>=314 && what_rule<332)
    { R9.NextRule(what_rule);
      if (what_rule<332) return; }
  if (what_rule>=332 && what_rule<350)
    { R10.NextRule(what_rule);
      if (what_rule<350) return; }
  if (what_rule>=350 && what_rule<368)
    { R11.NextRule(what_rule);
      if (what_rule<368) return; }
  if (what_rule>=368 && what_rule<422)
    { R12.NextRule(what_rule);
      if (what_rule<422) return; }
  if (what_rule>=422 && what_rule<440)
    { R13.NextRule(what_rule);
      if (what_rule<440) return; }
  if (what_rule>=440 && what_rule<458)
    { R14.NextRule(what_rule);
      if (what_rule<458) return; }
  if (what_rule>=458 && what_rule<476)
    { R15.NextRule(what_rule);
      if (what_rule<476) return; }
  if (what_rule>=476 && what_rule<530)
    { R16.NextRule(what_rule);
      if (what_rule<530) return; }
  if (what_rule>=530 && what_rule<548)
    { R17.NextRule(what_rule);
      if (what_rule<548) return; }
  if (what_rule>=548 && what_rule<566)
    { R18.NextRule(what_rule);
      if (what_rule<566) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=47) return R0.Condition(r-0);
  if (r>=48 && r<=151) return R1.Condition(r-48);
  if (r>=152 && r<=205) return R2.Condition(r-152);
  if (r>=206 && r<=223) return R3.Condition(r-206);
  if (r>=224 && r<=241) return R4.Condition(r-224);
  if (r>=242 && r<=259) return R5.Condition(r-242);
  if (r>=260 && r<=277) return R6.Condition(r-260);
  if (r>=278 && r<=295) return R7.Condition(r-278);
  if (r>=296 && r<=313) return R8.Condition(r-296);
  if (r>=314 && r<=331) return R9.Condition(r-314);
  if (r>=332 && r<=349) return R10.Condition(r-332);
  if (r>=350 && r<=367) return R11.Condition(r-350);
  if (r>=368 && r<=421) return R12.Condition(r-368);
  if (r>=422 && r<=439) return R13.Condition(r-422);
  if (r>=440 && r<=457) return R14.Condition(r-440);
  if (r>=458 && r<=475) return R15.Condition(r-458);
  if (r>=476 && r<=529) return R16.Condition(r-476);
  if (r>=530 && r<=547) return R17.Condition(r-530);
  if (r>=548 && r<=565) return R18.Condition(r-548);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=47) { R0.Code(r-0); return; } 
  if (r>=48 && r<=151) { R1.Code(r-48); return; } 
  if (r>=152 && r<=205) { R2.Code(r-152); return; } 
  if (r>=206 && r<=223) { R3.Code(r-206); return; } 
  if (r>=224 && r<=241) { R4.Code(r-224); return; } 
  if (r>=242 && r<=259) { R5.Code(r-242); return; } 
  if (r>=260 && r<=277) { R6.Code(r-260); return; } 
  if (r>=278 && r<=295) { R7.Code(r-278); return; } 
  if (r>=296 && r<=313) { R8.Code(r-296); return; } 
  if (r>=314 && r<=331) { R9.Code(r-314); return; } 
  if (r>=332 && r<=349) { R10.Code(r-332); return; } 
  if (r>=350 && r<=367) { R11.Code(r-350); return; } 
  if (r>=368 && r<=421) { R12.Code(r-368); return; } 
  if (r>=422 && r<=439) { R13.Code(r-422); return; } 
  if (r>=440 && r<=457) { R14.Code(r-440); return; } 
  if (r>=458 && r<=475) { R15.Code(r-458); return; } 
  if (r>=476 && r<=529) { R16.Code(r-476); return; } 
  if (r>=530 && r<=547) { R17.Code(r-530); return; } 
  if (r>=548 && r<=565) { R18.Code(r-548); return; } 
}
int Priority(unsigned short r)
{
  if (r<=47) { return R0.Priority(); } 
  if (r>=48 && r<=151) { return R1.Priority(); } 
  if (r>=152 && r<=205) { return R2.Priority(); } 
  if (r>=206 && r<=223) { return R3.Priority(); } 
  if (r>=224 && r<=241) { return R4.Priority(); } 
  if (r>=242 && r<=259) { return R5.Priority(); } 
  if (r>=260 && r<=277) { return R6.Priority(); } 
  if (r>=278 && r<=295) { return R7.Priority(); } 
  if (r>=296 && r<=313) { return R8.Priority(); } 
  if (r>=314 && r<=331) { return R9.Priority(); } 
  if (r>=332 && r<=349) { return R10.Priority(); } 
  if (r>=350 && r<=367) { return R11.Priority(); } 
  if (r>=368 && r<=421) { return R12.Priority(); } 
  if (r>=422 && r<=439) { return R13.Priority(); } 
  if (r>=440 && r<=457) { return R14.Priority(); } 
  if (r>=458 && r<=475) { return R15.Priority(); } 
  if (r>=476 && r<=529) { return R16.Priority(); } 
  if (r>=530 && r<=547) { return R17.Priority(); } 
  if (r>=548 && r<=565) { return R18.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=47) return R0.Name(r-0);
  if (r>=48 && r<=151) return R1.Name(r-48);
  if (r>=152 && r<=205) return R2.Name(r-152);
  if (r>=206 && r<=223) return R3.Name(r-206);
  if (r>=224 && r<=241) return R4.Name(r-224);
  if (r>=242 && r<=259) return R5.Name(r-242);
  if (r>=260 && r<=277) return R6.Name(r-260);
  if (r>=278 && r<=295) return R7.Name(r-278);
  if (r>=296 && r<=313) return R8.Name(r-296);
  if (r>=314 && r<=331) return R9.Name(r-314);
  if (r>=332 && r<=349) return R10.Name(r-332);
  if (r>=350 && r<=367) return R11.Name(r-350);
  if (r>=368 && r<=421) return R12.Name(r-368);
  if (r>=422 && r<=439) return R13.Name(r-422);
  if (r>=440 && r<=457) return R14.Name(r-440);
  if (r>=458 && r<=475) return R15.Name(r-458);
  if (r>=476 && r<=529) return R16.Name(r-476);
  if (r>=530 && r<=547) return R17.Name(r-530);
  if (r>=548 && r<=565) return R18.Name(r-548);
  return NULL;
}
};
const unsigned numrules = 566;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 566


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_h = 7; mu_h <= 8; mu_h++) {
mu_HomeNodes[mu_h].mu_state = mu_H_I;
mu_HomeNodes[mu_h].mu_owner.undefine();
mu_HomeNodes[mu_h].mu_sharers.undefine();
mu_HomeNodes[mu_h].mu_requester.undefine();
mu_HomeNodes[mu_h].mu_request_type.undefine();
mu_HomeNodes[mu_h].mu_val = 0;
};
};
mu_LastWrite0 = mu_HomeNodes[mu_Home0].mu_val;
mu_LastWrite1 = mu_HomeNodes[mu_Home1].mu_val;
{
for(int mu_i = 1; mu_i <= 6; mu_i++) {
mu_Procs[mu_i].mu_state = mu_P_I;
mu_Procs[mu_i].mu_val.undefine();
mu_Procs[mu_i].mu_addr.undefine();
mu_Procs[mu_i].mu_mem_write_val.undefine();
};
};
mu_Net.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_34() // Invariant "addr 1 values in shared state match memory"
{
bool mu__quant35; 
mu__quant35 = TRUE;
{
for(int mu_n = 1; mu_n <= 6; mu_n++) {
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
  if (!((mu_HomeNodes[mu_Home1].mu_state) == (mu_H_S))) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_Procs[mu_n].mu_state) == (mu_P_S)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_Procs[mu_n].mu_addr) == (1)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = TRUE ;
  else {
  mu__boolexpr36 = ((mu_HomeNodes[mu_Home1].mu_val) == (mu_Procs[mu_n].mu_val)) ; 
}
if ( !(mu__boolexpr36) )
  { mu__quant35 = FALSE; break; }
};
};
return mu__quant35;
};

bool mu__condition_39() // Condition for Rule "addr 1 values in shared state match memory"
{
  return mu__invariant_34( );
}

/**** end rule declaration ****/

int mu__invariant_40() // Invariant "addr 0 values in shared state match memory"
{
bool mu__quant41; 
mu__quant41 = TRUE;
{
for(int mu_n = 1; mu_n <= 6; mu_n++) {
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_HomeNodes[mu_Home0].mu_state) == (mu_H_S))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_Procs[mu_n].mu_state) == (mu_P_S)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_Procs[mu_n].mu_addr) == (0)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = TRUE ;
  else {
  mu__boolexpr42 = ((mu_HomeNodes[mu_Home0].mu_val) == (mu_Procs[mu_n].mu_val)) ; 
}
if ( !(mu__boolexpr42) )
  { mu__quant41 = FALSE; break; }
};
};
return mu__quant41;
};

bool mu__condition_45() // Condition for Rule "addr 0 values in shared state match memory"
{
  return mu__invariant_40( );
}

/**** end rule declaration ****/

int mu__invariant_46() // Invariant "Invalid implies empty sharer list"
{
bool mu__quant47; 
mu__quant47 = TRUE;
{
for(int mu_h = 7; mu_h <= 8; mu_h++) {
bool mu__boolexpr48;
  if (!((mu_HomeNodes[mu_h].mu_state) == (mu_H_I))) mu__boolexpr48 = TRUE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr49 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr49++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr48 = ((mu__intexpr49) == (0)) ; 
}
if ( !(mu__boolexpr48) )
  { mu__quant47 = FALSE; break; }
};
};
return mu__quant47;
};

bool mu__condition_50() // Condition for Rule "Invalid implies empty sharer list"
{
  return mu__invariant_46( );
}

/**** end rule declaration ****/

int mu__invariant_51() // Invariant "modified implies empty sharers list"
{
bool mu__quant52; 
mu__quant52 = TRUE;
{
for(int mu_h = 7; mu_h <= 8; mu_h++) {
bool mu__boolexpr53;
  if (!((mu_HomeNodes[mu_h].mu_state) == (mu_H_M))) mu__boolexpr53 = TRUE ;
  else {
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr54 = 0;
  {
  mu_1__type_8_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNodes[mu_h].mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr54++;
        }
      if (mu_i == 6-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
  mu__boolexpr53 = ((mu__intexpr54) == (0)) ; 
}
if ( !(mu__boolexpr53) )
  { mu__quant52 = FALSE; break; }
};
};
return mu__quant52;
};

bool mu__condition_55() // Condition for Rule "modified implies empty sharers list"
{
  return mu__invariant_51( );
}

/**** end rule declaration ****/

int mu__invariant_56() // Invariant "value in addr1 matches value of last write, when invalid"
{
bool mu__boolexpr57;
bool mu__boolexpr58;
  if ((mu_HomeNodes[mu_Home1].mu_state) == (mu_H_I)) mu__boolexpr58 = TRUE ;
  else {
  mu__boolexpr58 = ((mu_HomeNodes[mu_Home1].mu_state) == (mu_H_S)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = TRUE ;
  else {
  mu__boolexpr57 = ((mu_HomeNodes[mu_Home1].mu_val) == (mu_LastWrite1)) ; 
}
return mu__boolexpr57;
};

bool mu__condition_59() // Condition for Rule "value in addr1 matches value of last write, when invalid"
{
  return mu__invariant_56( );
}

/**** end rule declaration ****/

int mu__invariant_60() // Invariant "value in addr0 matches value of last write, when invalid"
{
bool mu__boolexpr61;
bool mu__boolexpr62;
  if ((mu_HomeNodes[mu_Home0].mu_state) == (mu_H_I)) mu__boolexpr62 = TRUE ;
  else {
  mu__boolexpr62 = ((mu_HomeNodes[mu_Home0].mu_state) == (mu_H_S)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = TRUE ;
  else {
  mu__boolexpr61 = ((mu_HomeNodes[mu_Home0].mu_val) == (mu_LastWrite0)) ; 
}
return mu__boolexpr61;
};

bool mu__condition_63() // Condition for Rule "value in addr0 matches value of last write, when invalid"
{
  return mu__invariant_60( );
}

/**** end rule declaration ****/

int mu__invariant_64() // Invariant "Invalid implies empty owner"
{
bool mu__quant65; 
mu__quant65 = TRUE;
{
for(int mu_h = 7; mu_h <= 8; mu_h++) {
bool mu__boolexpr66;
  if (!((mu_HomeNodes[mu_h].mu_state) == (mu_H_I))) mu__boolexpr66 = TRUE ;
  else {
  mu__boolexpr66 = (mu_HomeNodes[mu_h].mu_owner.isundefined()) ; 
}
if ( !(mu__boolexpr66) )
  { mu__quant65 = FALSE; break; }
};
};
return mu__quant65;
};

bool mu__condition_67() // Condition for Rule "Invalid implies empty owner"
{
  return mu__invariant_64( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invalid implies empty owner", &mu__condition_67, NULL, FALSE},
{"value in addr0 matches value of last write, when invalid", &mu__condition_63, NULL, FALSE},
{"value in addr1 matches value of last write, when invalid", &mu__condition_59, NULL, FALSE},
{"modified implies empty sharers list", &mu__condition_55, NULL, FALSE},
{"Invalid implies empty sharer list", &mu__condition_50, NULL, FALSE},
{"addr 0 values in shared state match memory", &mu__condition_45, NULL, FALSE},
{"addr 1 values in shared state match memory", &mu__condition_39, NULL, FALSE},
};
const unsigned short numinvariants = 7;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
LastWrite0:NoScalarset
msg_processed:NoScalarset
LastWrite1:NoScalarset
Procs:ScalarsetArrayOfFree
InBox:ScalarsetArrayOfScalarset
HomeNodes:Complex
Net:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Proc[6];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<6; i++)
      for (j=0; j<6; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[6];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[6];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm0(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<6; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<6; i++)
      for (j=0; j<6; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Proc Perm0[6];

  /********************
   declaration of class variables
  ********************/
  in = new bool[720];
 in_mu_1_Proc = new int[720];
 perm_mu_1_Proc = new arr_mu_1_Proc[720];
 revperm_mu_1_Proc = new arr_mu_1_Proc[720];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=6; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=720)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<720; i++)
      for (j=1; j<=6; j++)
        for (k=1; k<=6; k++)
          if (revperm_mu_1_Proc[i][k-1]==j)   // k - base 
            perm_mu_1_Proc[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Proc = 0;
    size = 720;
    count = 720;
    for (i=0; i<720; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 720) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<6; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<720; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Proc[6];
  int size_mu_1_Proc[6];
  bool should_be_in_mu_1_Proc[720];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<6; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<6; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<720; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<720; i++) // to be in or not to be
    for (k=0; k<6; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-1 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-1 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<720; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<6; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<6; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<6; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+1;
    }
  for (j=0; j<6; j++)
    for (k=0; k<6; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)
        perm_mu_1_Proc[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=6)
    {
      for (i=1; i<=6; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=6; i++)
        revperm_mu_1_Proc[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 6; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-1];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<6; j++)
    for (k=0; k<6; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)   // k - base 
	perm_mu_1_Proc[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_LastWrite0.MultisetSort();
        mu_msg_processed.MultisetSort();
        mu_LastWrite1.MultisetSort();
        mu_Procs.MultisetSort();
        mu_InBox.MultisetSort();
        mu_HomeNodes.MultisetSort();
        mu_Net.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<6; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        value(1 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-1]+1);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<6; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Home::Permute(PermSet& Perm, int i) {};
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Home::Canonicalize(PermSet& Perm) {};
void mu_1_Home::SimpleLimit(PermSet& Perm) {};
void mu_1_Home::ArrayLimit(PermSet& Perm) {};
void mu_1_Home::Limit(PermSet& Perm) {};
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_UQIDType::Permute(PermSet& Perm, int i) {}
void mu_1_UQIDType::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_UQIDType::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_UQIDType::SimpleLimit(PermSet& Perm) {}
void mu_1_UQIDType::ArrayLimit(PermSet& Perm) {}
void mu_1_UQIDType::Limit(PermSet& Perm) {}
void mu_1_UQIDType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_MESIType::Permute(PermSet& Perm, int i) {};
void mu_1_MESIType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MESIType::Canonicalize(PermSet& Perm) {};
void mu_1_MESIType::SimpleLimit(PermSet& Perm) {};
void mu_1_MESIType::ArrayLimit(PermSet& Perm) {};
void mu_1_MESIType::Limit(PermSet& Perm) {};
void mu_1_MESIType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_RspData::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_RspData::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_RspData::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_RspData::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_RspData::ArrayLimit(PermSet& Perm) {}
void mu_1_RspData::Limit(PermSet& Perm) {}
void mu_1_RspData::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i) {};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Value::Canonicalize(PermSet& Perm) {};
void mu_1_Value::SimpleLimit(PermSet& Perm) {};
void mu_1_Value::ArrayLimit(PermSet& Perm) {};
void mu_1_Value::Limit(PermSet& Perm) {};
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Address::Permute(PermSet& Perm, int i) {};
void mu_1_Address::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Address::Canonicalize(PermSet& Perm) {};
void mu_1_Address::SimpleLimit(PermSet& Perm) {};
void mu_1_Address::ArrayLimit(PermSet& Perm) {};
void mu_1_Address::Limit(PermSet& Perm) {};
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 6 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 6 ) )
      {
        if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<6; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
                Perm.class_mu_1_Proc[i]++;
            value(1 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-1]+1);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 6 ) )
      if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<6; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_VCType::Permute(PermSet& Perm, int i) {};
void mu_1_VCType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_VCType::Canonicalize(PermSet& Perm) {};
void mu_1_VCType::SimpleLimit(PermSet& Perm) {};
void mu_1_VCType::ArrayLimit(PermSet& Perm) {};
void mu_1_VCType::Limit(PermSet& Perm) {};
void mu_1_VCType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_SharerNum::Permute(PermSet& Perm, int i) {};
void mu_1_SharerNum::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_SharerNum::Canonicalize(PermSet& Perm) {};
void mu_1_SharerNum::SimpleLimit(PermSet& Perm) {};
void mu_1_SharerNum::ArrayLimit(PermSet& Perm) {};
void mu_1_SharerNum::Limit(PermSet& Perm) {};
void mu_1_SharerNum::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i) {};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_5::Canonicalize(PermSet& Perm) {};
void mu_1__type_5::SimpleLimit(PermSet& Perm) {};
void mu_1__type_5::ArrayLimit(PermSet& Perm) {};
void mu_1__type_5::Limit(PermSet& Perm) {};
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i) {};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_6::Canonicalize(PermSet& Perm) {};
void mu_1__type_6::SimpleLimit(PermSet& Perm) {};
void mu_1__type_6::ArrayLimit(PermSet& Perm) {};
void mu_1__type_6::Limit(PermSet& Perm) {};
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_rspdata.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_rspdata.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_7::Permute(PermSet& Perm, int i) {};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_7::Canonicalize(PermSet& Perm) {};
void mu_1__type_7::SimpleLimit(PermSet& Perm) {};
void mu_1__type_7::ArrayLimit(PermSet& Perm) {};
void mu_1__type_7::Limit(PermSet& Perm) {};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<6; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_8::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_8::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_8::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_8::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[6];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[6][6];
  bool goodset_mu_1_Proc[6];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[6][6];
  bool goodset_multisetindex[6];
  mu_1_Node temp;

  // compact
  for (i = 0, j = 0; i < 6; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 6; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 6; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<6; i++)
    for (j=0; j<6; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<6; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].isundefined())
                && (*this)[k]>=1
                && (*this)[k]<=6)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<6; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].isundefined()
                          && (*this)[k]>=1
                          && (*this)[k]<=6
                          && pos_mu_1_Proc[j][(*this)[k]-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k]-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<6; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<6; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<6; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Proc<6;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<6; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_9::Permute(PermSet& Perm, int i) {};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_9::Canonicalize(PermSet& Perm) {};
void mu_1__type_9::SimpleLimit(PermSet& Perm) {};
void mu_1__type_9::ArrayLimit(PermSet& Perm) {};
void mu_1__type_9::Limit(PermSet& Perm) {};
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i) {};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_10::Canonicalize(PermSet& Perm) {};
void mu_1__type_10::SimpleLimit(PermSet& Perm) {};
void mu_1__type_10::ArrayLimit(PermSet& Perm) {};
void mu_1__type_10::Limit(PermSet& Perm) {};
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
  mu_owner.Permute(Perm,i);
  mu_sharers.Permute(Perm,i);
  mu_requester.Permute(Perm,i);
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_owner.SimpleCanonicalize(Perm);
  mu_requester.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_owner.SimpleLimit(Perm);
  mu_requester.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
  mu_sharers.Limit(Perm);
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
  mu_sharers.MultisetLimit(Perm);
};
void mu_1__type_11::Permute(PermSet& Perm, int i) {};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_11::Canonicalize(PermSet& Perm) {};
void mu_1__type_11::SimpleLimit(PermSet& Perm) {};
void mu_1__type_11::ArrayLimit(PermSet& Perm) {};
void mu_1__type_11::Limit(PermSet& Perm) {};
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm){}
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_12::Permute(PermSet& Perm, int i)
{
  static mu_1__type_12 temp("Permute_mu_1__type_12",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_12::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<2; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_12::Canonicalize(PermSet& Perm){};
void mu_1__type_12::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<2; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_12::ArrayLimit(PermSet& Perm) {}
void mu_1__type_12::Limit(PermSet& Perm){}
void mu_1__type_12::MultisetLimit(PermSet& Perm)
{
  for (int j=0; j<2; j++) {
    array[j].MultisetLimit(Perm);
  }
}
void mu_1__type_13::Permute(PermSet& Perm, int i)
{
  static mu_1__type_13 temp("Permute_mu_1__type_13",-1);
  int j;
  for (j=0; j<6; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=6; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];};
void mu_1__type_13::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_13::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[6];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[6];
  bool pos_mu_1_Proc[6][6];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_Proc[6];
  int start_mu_1_Proc[6];
  // canonicalization
  static mu_1__type_13 temp;
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<6; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<6; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<6; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<6; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<6; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<6; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<6; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<6; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<6; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_Proc())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_Proc; j++) // class number
        {
          class_size = 0;
          for (k=0; k<6; k++) // step through class[k]
            if (Perm.class_mu_1_Proc[k]==j)
              class_size++;
          for (k=0; k<6; k++) // step through class[k]
            if (Perm.class_mu_1_Proc[k]==j)
              {
                size_mu_1_Proc[k] = class_size;
                start_mu_1_Proc[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
         if (i >=start_mu_1_Proc[j] 
             && i < start_mu_1_Proc[j] + size_mu_1_Proc[j])
           {
             array[i+0] = temp[j+1];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<6; j++)
        array[Perm.class_mu_1_Proc[j]+0] = temp[j+1];
    }
}
void mu_1__type_13::SimpleLimit(PermSet& Perm){}
void mu_1__type_13::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[6];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[6];
  bool pos_mu_1_Proc[6][6];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<6; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<6; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<6; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<6; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<6; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<6; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<6; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<6; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<6; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_13::Limit(PermSet& Perm){}
void mu_1__type_13::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_14::Permute(PermSet& Perm, int i)
{
  static mu_1__type_14 temp("Permute_mu_1__type_14",-1);
  int j;
  for (j=0; j<13; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_14::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_14::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_14::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[13];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[6][6];
  bool goodset_mu_1_Proc[6];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[13][13];
  bool goodset_multisetindex[13];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 13; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 13; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 13; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<6; i++)
    for (j=0; j<6; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<6; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=1
                && (*this)[k].mu_src<=6)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<6; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=1
                          && (*this)[k].mu_src<=6
                          && pos_mu_1_Proc[j][(*this)[k].mu_src-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_src-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<6; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<6; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<6; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Proc<6;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<6; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_15::Permute(PermSet& Perm, int i)
{
  static mu_1__type_15 temp("Permute_mu_1__type_15",-1);
  int j;
  for (j=0; j<8; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=6; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_15::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_15::Canonicalize(PermSet& Perm){};
void mu_1__type_15::SimpleLimit(PermSet& Perm){}
void mu_1__type_15::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_14 value[8];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[6][6];
  bool goodset_mu_1_Proc[6];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<6; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<6; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<6; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<6; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<6; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<6; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<6; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<6; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<6; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_15::Limit(PermSet& Perm){}
void mu_1__type_15::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_16::Permute(PermSet& Perm, int i)
{
  static mu_1__type_16 temp("Permute_mu_1__type_16",-1);
  int j;
  for (j=0; j<6; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_16::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<6; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_16::Canonicalize(PermSet& Perm){};
void mu_1__type_16::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<6; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_16::ArrayLimit(PermSet& Perm) {}
void mu_1__type_16::Limit(PermSet& Perm){}
void mu_1__type_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_17::Permute(PermSet& Perm, int i)
{
  static mu_1__type_17 temp("Permute_mu_1__type_17",-1);
  int j;
  for (j=0; j<8; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=6; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_17::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_17::Canonicalize(PermSet& Perm){};
void mu_1__type_17::SimpleLimit(PermSet& Perm){}
void mu_1__type_17::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_16 value[8];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[6][6];
  bool goodset_mu_1_Proc[6];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<6; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<6; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<6; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<6; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<6; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<6; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<6; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<6; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<6; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_17::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_16 value[8];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[6][6];
  bool goodset_mu_1_Proc[6];
  // initializing pos array
  for (i=0; i<6; i++)
    for (j=0; j<6; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<6; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 5; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<6; k++) // step through class
        if ((*this)[k+1][i0].mu_src.isundefined()
            ||(*this)[k+1][i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<6; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<6; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1][i0].mu_src.isundefined()
                    && (*this)[k+1][i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<6; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<6; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<6; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 5; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<6)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<6; k++) // step through class
            if (!(*this)[k+1][i0].mu_src.isundefined()
                &&(*this)[k+1][i0].mu_src!=k+1
                &&(*this)[k+1][i0].mu_src>=1
                &&(*this)[k+1][i0].mu_src<=6)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<6; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<6; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1][i0].mu_src.isundefined()
                            && (*this)[k+1][i0].mu_src!=k+1
                            && (*this)[k+1][i0].mu_src>=1
                            && (*this)[k+1][i0].mu_src<=6
                            && pos_mu_1_Proc[j][(*this)[k+1][i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<6; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<6; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<6; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 5; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<6;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<6; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
}
void mu_1__type_17::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_18::Permute(PermSet& Perm, int i) {};
void mu_1__type_18::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_18::Canonicalize(PermSet& Perm) {};
void mu_1__type_18::SimpleLimit(PermSet& Perm) {};
void mu_1__type_18::ArrayLimit(PermSet& Perm) {};
void mu_1__type_18::Limit(PermSet& Perm) {};
void mu_1__type_18::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_19::Permute(PermSet& Perm, int i) {};
void mu_1__type_19::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_19::Canonicalize(PermSet& Perm) {};
void mu_1__type_19::SimpleLimit(PermSet& Perm) {};
void mu_1__type_19::ArrayLimit(PermSet& Perm) {};
void mu_1__type_19::Limit(PermSet& Perm) {};
void mu_1__type_19::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_20::Permute(PermSet& Perm, int i) {};
void mu_1__type_20::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_20::Canonicalize(PermSet& Perm) {};
void mu_1__type_20::SimpleLimit(PermSet& Perm) {};
void mu_1__type_20::ArrayLimit(PermSet& Perm) {};
void mu_1__type_20::Limit(PermSet& Perm) {};
void mu_1__type_20::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_21::Permute(PermSet& Perm, int i) {};
void mu_1__type_21::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_21::Canonicalize(PermSet& Perm) {};
void mu_1__type_21::SimpleLimit(PermSet& Perm) {};
void mu_1__type_21::ArrayLimit(PermSet& Perm) {};
void mu_1__type_21::Limit(PermSet& Perm) {};
void mu_1__type_21::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_22::Permute(PermSet& Perm, int i) {};
void mu_1__type_22::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_22::Canonicalize(PermSet& Perm) {};
void mu_1__type_22::SimpleLimit(PermSet& Perm) {};
void mu_1__type_22::ArrayLimit(PermSet& Perm) {};
void mu_1__type_22::Limit(PermSet& Perm) {};
void mu_1__type_22::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_23::Permute(PermSet& Perm, int i) {};
void mu_1__type_23::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_23::Canonicalize(PermSet& Perm) {};
void mu_1__type_23::SimpleLimit(PermSet& Perm) {};
void mu_1__type_23::ArrayLimit(PermSet& Perm) {};
void mu_1__type_23::Limit(PermSet& Perm) {};
void mu_1__type_23::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_24::Permute(PermSet& Perm, int i) {};
void mu_1__type_24::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_24::Canonicalize(PermSet& Perm) {};
void mu_1__type_24::SimpleLimit(PermSet& Perm) {};
void mu_1__type_24::ArrayLimit(PermSet& Perm) {};
void mu_1__type_24::Limit(PermSet& Perm) {};
void mu_1__type_24::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_LastWrite0.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite0.MultisetSort();
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite1.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_HomeNodes.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_HomeNodes.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_LastWrite0.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite0.MultisetSort();
          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_LastWrite1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite1.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_InBox.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_InBox.MultisetSort();
          mu_HomeNodes.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_HomeNodes.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_LastWrite0.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite0.MultisetSort();
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite1.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_HomeNodes.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_HomeNodes.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_LastWrite0.MultisetSort();
      mu_msg_processed.MultisetSort();
      mu_LastWrite1.MultisetSort();
      mu_Procs.MultisetSort();
      mu_InBox.MultisetSort();
      mu_HomeNodes.MultisetSort();
      mu_Net.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite0.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite0.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNodes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNodes.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNodes.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNodes.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNodes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNodes.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNodes.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNodes.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();
  mu_HomeNodes.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_HomeNodes.MultisetSort();
  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_InBox.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_InBox.MultisetSort();
      mu_HomeNodes.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_HomeNodes.MultisetSort();
      mu_Net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Net.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNodes.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();

  mu_HomeNodes.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_HomeNodes.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
