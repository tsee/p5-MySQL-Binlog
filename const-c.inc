#define STRING_TYPE_td User_var_event::STRING_TYPE
#define REAL_TYPE_td User_var_event::REAL_TYPE
#define INT_TYPE_td User_var_event::INT_TYPE
#define ROW_TYPE_td User_var_event::ROW_TYPE
#define DECIMAL_TYPE_td User_var_event::DECIMAL_TYPE
#define VALUE_TYPE_COUNT_td User_var_event::VALUE_TYPE_COUNT
#define STMT_END_F_td Row_event::STMT_END_F
#define NO_FOREIGN_KEY_CHECKS_F_td Row_event::NO_FOREIGN_KEY_CHECKS_F
#define RELAXED_UNIQUE_CHECKS_F_td Row_event::RELAXED_UNIQUE_CHECKS_F
#define COMPLETE_ROWS_F_td Row_event::COMPLETE_ROWS_F
#define INVALID_INT_EVENT_td Int_var_event::INVALID_INT_EVENT
#define LAST_INSERT_ID_EVENT_td Int_var_event::LAST_INSERT_ID_EVENT
#define INSERT_ID_EVENT_td Int_var_event::INSERT_ID_EVENT
#define PERL_constant_NOTFOUND	1
#define PERL_constant_NOTDEF	2
#define PERL_constant_ISIV	3
#define PERL_constant_ISNO	4
#define PERL_constant_ISNV	5
#define PERL_constant_ISPV	6
#define PERL_constant_ISPVN	7
#define PERL_constant_ISSV	8
#define PERL_constant_ISUNDEF	9
#define PERL_constant_ISUV	10
#define PERL_constant_ISYES	11

#ifndef NVTYPE
typedef double NV; /* 5.6 and later define NVTYPE, and typedef NV to it.  */
#endif
#ifndef aTHX_
#define aTHX_ /* 5.6 or later define this for threading support.  */
#endif
#ifndef pTHX_
#define pTHX_ /* 5.6 or later define this for threading support.  */
#endif

static int
constant_10 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     LOAD_EVENT RAND_EVENT STMT_END_F_td STOP_EVENT */
  /* Offset 2 gives the best switch position.  */
  switch (name[2]) {
  case 'A':
    if (memEQ(name, "LOAD_EVENT", 10)) {
    /*                 ^              */
      *iv_return = LOAD_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'M':
    if (memEQ(name, "STMT_END_F", 10)) {
    /*                 ^              */
      *iv_return = STMT_END_F_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'N':
    if (memEQ(name, "RAND_EVENT", 10)) {
    /*                 ^              */
      *iv_return = RAND_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'O':
    if (memEQ(name, "STOP_EVENT", 10)) {
    /*                 ^              */
      *iv_return = STOP_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_11 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     QUERY_EVENT SLAVE_EVENT STRING_TYPE_td */
  /* Offset 1 gives the best switch position.  */
  switch (name[1]) {
  case 'L':
    if (memEQ(name, "SLAVE_EVENT", 11)) {
    /*                ^                */
      *iv_return = SLAVE_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'T':
    if (memEQ(name, "STRING_TYPE", 11)) {
    /*                ^                */
      *iv_return = STRING_TYPE_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'U':
    if (memEQ(name, "QUERY_EVENT", 11)) {
    /*                ^                */
      *iv_return = QUERY_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_12 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     DECIMAL_TYPE_td INTVAR_EVENT ROTATE_EVENT USER_DEFINED */
  /* Offset 1 gives the best switch position.  */
  switch (name[1]) {
  case 'E':
    if (memEQ(name, "DECIMAL_TYPE", 12)) {
    /*                ^                 */
      *iv_return = DECIMAL_TYPE_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'N':
    if (memEQ(name, "INTVAR_EVENT", 12)) {
    /*                ^                 */
      *iv_return = INTVAR_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'O':
    if (memEQ(name, "ROTATE_EVENT", 12)) {
    /*                ^                 */
      *iv_return = ROTATE_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'S':
    if (memEQ(name, "USER_DEFINED", 12)) {
    /*                ^                 */
      *iv_return = USER_DEFINED;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_14 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     ENUM_END_EVENT GTID_LOG_EVENT INCIDENT_EVENT NEW_LOAD_EVENT START_EVENT_V3
     USER_VAR_EVENT */
  /* Offset 0 gives the best switch position.  */
  switch (*name++) {
  case 'E':
    if (memEQ(name, "NUM_END_EVENT", 13)) {
    /*                E                    */
      *iv_return = ENUM_END_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'G':
    if (memEQ(name, "TID_LOG_EVENT", 13)) {
    /*                G                    */
      *iv_return = GTID_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'I':
    if (memEQ(name, "NCIDENT_EVENT", 13)) {
    /*                I                    */
      *iv_return = INCIDENT_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'N':
    if (memEQ(name, "EW_LOAD_EVENT", 13)) {
    /*                N                    */
      *iv_return = NEW_LOAD_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'S':
    if (memEQ(name, "TART_EVENT_V3", 13)) {
    /*                S                    */
      *iv_return = START_EVENT_V3;
      return PERL_constant_ISIV;

    }
    break;
  case 'U':
    if (memEQ(name, "SER_VAR_EVENT", 13)) {
    /*                U                    */
      *iv_return = USER_VAR_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_15 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     COMPLETE_ROWS_F_td EXEC_LOAD_EVENT INSERT_ID_EVENT_td TABLE_MAP_EVENT */
  /* Offset 3 gives the best switch position.  */
  switch (name[3]) {
  case 'C':
    if (memEQ(name, "EXEC_LOAD_EVENT", 15)) {
    /*                  ^                  */
      *iv_return = EXEC_LOAD_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'E':
    if (memEQ(name, "INSERT_ID_EVENT", 15)) {
    /*                  ^                  */
      *iv_return = INSERT_ID_EVENT_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'L':
    if (memEQ(name, "TABLE_MAP_EVENT", 15)) {
    /*                  ^                  */
      *iv_return = TABLE_MAP_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'P':
    if (memEQ(name, "COMPLETE_ROWS_F", 15)) {
    /*                  ^                  */
      *iv_return = COMPLETE_ROWS_F_td;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_17 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CREATE_FILE_EVENT DELETE_FILE_EVENT DELETE_ROWS_EVENT INVALID_INT_EVENT_td
     UPDATE_ROWS_EVENT */
  /* Offset 1 gives the best switch position.  */
  switch (name[1]) {
  case 'E':
    if (memEQ(name, "DELETE_FILE_EVENT", 17)) {
    /*                ^                      */
      *iv_return = DELETE_FILE_EVENT;
      return PERL_constant_ISIV;

    }
    if (memEQ(name, "DELETE_ROWS_EVENT", 17)) {
    /*                ^                      */
      *iv_return = DELETE_ROWS_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'N':
    if (memEQ(name, "INVALID_INT_EVENT", 17)) {
    /*                ^                      */
      *iv_return = INVALID_INT_EVENT_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'P':
    if (memEQ(name, "UPDATE_ROWS_EVENT", 17)) {
    /*                ^                      */
      *iv_return = UPDATE_ROWS_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'R':
    if (memEQ(name, "CREATE_FILE_EVENT", 17)) {
    /*                ^                      */
      *iv_return = CREATE_FILE_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_19 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HEARTBEAT_LOG_EVENT IGNORABLE_LOG_EVENT WRITE_ROWS_EVENT_V1 */
  /* Offset 3 gives the best switch position.  */
  switch (name[3]) {
  case 'O':
    if (memEQ(name, "IGNORABLE_LOG_EVENT", 19)) {
    /*                  ^                      */
      *iv_return = IGNORABLE_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'R':
    if (memEQ(name, "HEARTBEAT_LOG_EVENT", 19)) {
    /*                  ^                      */
      *iv_return = HEARTBEAT_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'T':
    if (memEQ(name, "WRITE_ROWS_EVENT_V1", 19)) {
    /*                  ^                      */
      *iv_return = WRITE_ROWS_EVENT_V1;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_20 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     DELETE_ROWS_EVENT_V1 LAST_INSERT_ID_EVENT_td ROWS_QUERY_LOG_EVENT
     UPDATE_ROWS_EVENT_V1 */
  /* Offset 1 gives the best switch position.  */
  switch (name[1]) {
  case 'A':
    if (memEQ(name, "LAST_INSERT_ID_EVENT", 20)) {
    /*                ^                         */
      *iv_return = LAST_INSERT_ID_EVENT_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'E':
    if (memEQ(name, "DELETE_ROWS_EVENT_V1", 20)) {
    /*                ^                         */
      *iv_return = DELETE_ROWS_EVENT_V1;
      return PERL_constant_ISIV;

    }
    break;
  case 'O':
    if (memEQ(name, "ROWS_QUERY_LOG_EVENT", 20)) {
    /*                ^                         */
      *iv_return = ROWS_QUERY_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'P':
    if (memEQ(name, "UPDATE_ROWS_EVENT_V1", 20)) {
    /*                ^                         */
      *iv_return = UPDATE_ROWS_EVENT_V1;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_23 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     NO_FOREIGN_KEY_CHECKS_F_td PRE_GA_WRITE_ROWS_EVENT RELAXED_UNIQUE_CHECKS_F_td */
  /* Offset 0 gives the best switch position.  */
  switch (*name++) {
  case 'N':
    if (memEQ(name, "O_FOREIGN_KEY_CHECKS_F", 22)) {
    /*                N                             */
      *iv_return = NO_FOREIGN_KEY_CHECKS_F_td;
      return PERL_constant_ISIV;

    }
    break;
  case 'P':
    if (memEQ(name, "RE_GA_WRITE_ROWS_EVENT", 22)) {
    /*                P                             */
      *iv_return = PRE_GA_WRITE_ROWS_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'R':
    if (memEQ(name, "ELAXED_UNIQUE_CHECKS_F", 22)) {
    /*                R                             */
      *iv_return = RELAXED_UNIQUE_CHECKS_F_td;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_24 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     ANONYMOUS_GTID_LOG_EVENT EXECUTE_LOAD_QUERY_EVENT FORMAT_DESCRIPTION_EVENT
     PREVIOUS_GTIDS_LOG_EVENT PRE_GA_DELETE_ROWS_EVENT PRE_GA_UPDATE_ROWS_EVENT
     */
  /* Offset 9 gives the best switch position.  */
  switch (name[9]) {
  case 'D':
    if (memEQ(name, "PRE_GA_UPDATE_ROWS_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = PRE_GA_UPDATE_ROWS_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'G':
    if (memEQ(name, "PREVIOUS_GTIDS_LOG_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = PREVIOUS_GTIDS_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'L':
    if (memEQ(name, "PRE_GA_DELETE_ROWS_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = PRE_GA_DELETE_ROWS_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'O':
    if (memEQ(name, "EXECUTE_LOAD_QUERY_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = EXECUTE_LOAD_QUERY_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 'S':
    if (memEQ(name, "FORMAT_DESCRIPTION_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = FORMAT_DESCRIPTION_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case '_':
    if (memEQ(name, "ANONYMOUS_GTID_LOG_EVENT", 24)) {
    /*                        ^                     */
      *iv_return = ANONYMOUS_GTID_LOG_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant (pTHX_ const char *name, STRLEN len, IV *iv_return) {
  /* Initially switch on the length of the name.  */
  /* When generated this function returned values for the list of names given
     in this section of perl code.  Rather than manually editing these functions
     to add or remove constants, which would result in this comment and section
     of code becoming inaccurate, we recommend that you edit this section of
     code, and use it to regenerate a new set of constant functions which you
     then use to replace the originals.

     Regenerate these constant functions by feeding this entire source file to
     perl -x

#!/usr/bin/perl -w
use ExtUtils::Constant qw (constant_types C_constant XS_constant);

my $types = {map {($_, 1)} qw(IV)};
my @names = (qw(ANONYMOUS_GTID_LOG_EVENT APPEND_BLOCK_EVENT
	       BEGIN_LOAD_QUERY_EVENT COMPLETE_ROWS_F_td CREATE_FILE_EVENT
	       DECIMAL_TYPE_td DELETE_FILE_EVENT DELETE_ROWS_EVENT
	       DELETE_ROWS_EVENT_V1 ENUM_END_EVENT EXECUTE_LOAD_QUERY_EVENT
	       EXEC_LOAD_EVENT FORMAT_DESCRIPTION_EVENT GTID_LOG_EVENT
	       HEARTBEAT_LOG_EVENT IGNORABLE_LOG_EVENT INCIDENT_EVENT
	       INSERT_ID_EVENT_td INTVAR_EVENT INT_TYPE_td INVALID_INT_EVENT_td
	       LAST_INSERT_ID_EVENT_td LOAD_EVENT NEW_LOAD_EVENT
	       NO_FOREIGN_KEY_CHECKS_F_td PREVIOUS_GTIDS_LOG_EVENT
	       PRE_GA_DELETE_ROWS_EVENT PRE_GA_UPDATE_ROWS_EVENT
	       PRE_GA_WRITE_ROWS_EVENT QUERY_EVENT RAND_EVENT REAL_TYPE_td
	       RELAXED_UNIQUE_CHECKS_F_td ROTATE_EVENT ROWS_QUERY_LOG_EVENT
	       ROW_TYPE_td SLAVE_EVENT START_EVENT_V3 STMT_END_F_td STOP_EVENT
	       STRING_TYPE_td TABLE_MAP_EVENT UNKNOWN_EVENT UPDATE_ROWS_EVENT
	       UPDATE_ROWS_EVENT_V1 USER_DEFINED USER_VAR_EVENT
	       VALUE_TYPE_COUNT_td WRITE_ROWS_EVENT WRITE_ROWS_EVENT_V1 XID_EVENT));

print constant_types(), "\n"; # macro defs
foreach (C_constant ("MySQL::Binlog", 'constant', 'IV', $types, undef, 3, @names) ) {
    print $_, "\n"; # C constant subs
}
print "\n#### XS Section:\n";
print XS_constant ("MySQL::Binlog", $types);
__END__
   */

  switch (len) {
  case 8:
    /* Names all of length 8.  */
    /* INT_TYPE_td ROW_TYPE_td */
    /* Offset 1 gives the best switch position.  */
    switch (name[1]) {
    case 'N':
      if (memEQ(name, "INT_TYPE", 8)) {
      /*                ^            */
        *iv_return = INT_TYPE_td;
        return PERL_constant_ISIV;

      }
      break;
    case 'O':
      if (memEQ(name, "ROW_TYPE", 8)) {
      /*                ^            */
        *iv_return = ROW_TYPE_td;
        return PERL_constant_ISIV;

      }
      break;
    }
    break;
  case 9:
    /* Names all of length 9.  */
    /* REAL_TYPE_td XID_EVENT */
    /* Offset 5 gives the best switch position.  */
    switch (name[5]) {
    case 'T':
      if (memEQ(name, "REAL_TYPE", 9)) {
      /*                    ^         */
        *iv_return = REAL_TYPE_td;
        return PERL_constant_ISIV;

      }
      break;
    case 'V':
      if (memEQ(name, "XID_EVENT", 9)) {
      /*                    ^         */
        *iv_return = XID_EVENT;
        return PERL_constant_ISIV;

      }
      break;
    }
    break;
  case 10:
    return constant_10 (aTHX_ name, iv_return);
    break;
  case 11:
    return constant_11 (aTHX_ name, iv_return);
    break;
  case 12:
    return constant_12 (aTHX_ name, iv_return);
    break;
  case 13:
    if (memEQ(name, "UNKNOWN_EVENT", 13)) {
      *iv_return = UNKNOWN_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 14:
    return constant_14 (aTHX_ name, iv_return);
    break;
  case 15:
    return constant_15 (aTHX_ name, iv_return);
    break;
  case 16:
    /* Names all of length 16.  */
    /* VALUE_TYPE_COUNT_td WRITE_ROWS_EVENT */
    /* Offset 0 gives the best switch position.  */
    switch (*name++) {
    case 'V':
      if (memEQ(name, "ALUE_TYPE_COUNT", 15)) {
      /*                V                      */
        *iv_return = VALUE_TYPE_COUNT_td;
        return PERL_constant_ISIV;

      }
      break;
    case 'W':
      if (memEQ(name, "RITE_ROWS_EVENT", 15)) {
      /*                W                      */
        *iv_return = WRITE_ROWS_EVENT;
        return PERL_constant_ISIV;

      }
      break;
    }
    break;
  case 17:
    return constant_17 (aTHX_ name, iv_return);
    break;
  case 18:
    if (memEQ(name, "APPEND_BLOCK_EVENT", 18)) {
      *iv_return = APPEND_BLOCK_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 19:
    return constant_19 (aTHX_ name, iv_return);
    break;
  case 20:
    return constant_20 (aTHX_ name, iv_return);
    break;
  case 22:
    if (memEQ(name, "BEGIN_LOAD_QUERY_EVENT", 22)) {
      *iv_return = BEGIN_LOAD_QUERY_EVENT;
      return PERL_constant_ISIV;

    }
    break;
  case 23:
    return constant_23 (aTHX_ name, iv_return);
    break;
  case 24:
    return constant_24 (aTHX_ name, iv_return);
    break;
  }
  return PERL_constant_NOTFOUND;
}

const char *
mbl_event_id_to_perl_class(IV event_id)
{
  switch (event_id) {
  case NEW_LOAD_EVENT:
    return "MySQL::Binlog::Event::NewLoad";
  case SLAVE_EVENT:
    return "MySQL::Binlog::Event::Slave";
  case WRITE_ROWS_EVENT_V1:
    return "MySQL::Binlog::Event::WriteRowsV1";
  case ROTATE_EVENT:
    return "MySQL::Binlog::Event::Rotate";
  case ROWS_QUERY_LOG_EVENT:
    return "MySQL::Binlog::Event::RowsQueryLog";
  case DELETE_ROWS_EVENT_V1:
    return "MySQL::Binlog::Event::DeleteRowsV1";
  case INCIDENT_EVENT:
    return "MySQL::Binlog::Event::Incident";
  case PRE_GA_DELETE_ROWS_EVENT:
    return "MySQL::Binlog::Event::PreGaDeleteRows";
  case TABLE_MAP_EVENT:
    return "MySQL::Binlog::Event::TableMap";
  case INTVAR_EVENT:
    return "MySQL::Binlog::Event::IntVar";
  case PRE_GA_UPDATE_ROWS_EVENT:
    return "MySQL::Binlog::Event::PreGaUpdateRows";
  case PREVIOUS_GTIDS_LOG_EVENT:
    return "MySQL::Binlog::Event::PreviousGtidsLog";
  case FORMAT_DESCRIPTION_EVENT:
    return "MySQL::Binlog::Event::Format";
  case EXEC_LOAD_EVENT:
    return "MySQL::Binlog::Event::ExecLoad";
  case ENUM_END_EVENT:
    return "MySQL::Binlog::Event::EnumEnd";
  case EXECUTE_LOAD_QUERY_EVENT:
    return "MySQL::Binlog::Event::ExecuteLoadQuery";
  case XID_EVENT:
    return "MySQL::Binlog::Event::Xid";
  case STOP_EVENT:
    return "MySQL::Binlog::Event::Stop";
  case DELETE_FILE_EVENT:
    return "MySQL::Binlog::Event::DeleteFile";
  case LOAD_EVENT:
    return "MySQL::Binlog::Event::Load";
  case HEARTBEAT_LOG_EVENT:
    return "MySQL::Binlog::Event::HeartbeatLog";
  case BEGIN_LOAD_QUERY_EVENT:
    return "MySQL::Binlog::Event::BeginLoadQuery";
  case PRE_GA_WRITE_ROWS_EVENT:
    return "MySQL::Binlog::Event::PreGaWriteRows";
  case QUERY_EVENT:
    return "MySQL::Binlog::Event::Query";
  case USER_VAR_EVENT:
    return "MySQL::Binlog::Event::UserVar";
  case GTID_LOG_EVENT:
    return "MySQL::Binlog::Event::GtidLog";
  case IGNORABLE_LOG_EVENT:
    return "MySQL::Binlog::Event::IgnorableLog";
  case UPDATE_ROWS_EVENT_V1:
    return "MySQL::Binlog::Event::UpdateRowsV1";
  case CREATE_FILE_EVENT:
    return "MySQL::Binlog::Event::CreateFile";
  case DELETE_ROWS_EVENT:
    return "MySQL::Binlog::Event::DeleteRows";
  case USER_DEFINED:
    return "MySQL::Binlog::Event::UserDefined";
  case RAND_EVENT:
    return "MySQL::Binlog::Event::Rand";
  case START_EVENT_V3:
    return "MySQL::Binlog::Event::StartV3";
  case WRITE_ROWS_EVENT:
    return "MySQL::Binlog::Event::WriteRows";
  case ANONYMOUS_GTID_LOG_EVENT:
    return "MySQL::Binlog::Event::AnonymousGtidLog";
  case UPDATE_ROWS_EVENT:
    return "MySQL::Binlog::Event::UpdateRows";
  case UNKNOWN_EVENT:
    return "MySQL::Binlog::Event::Unknown";
  case APPEND_BLOCK_EVENT:
    return "MySQL::Binlog::Event::AppendBlock";
  default:
    {
      dTHX;
      croak("Invalid event id '%i'!", (int)event_id);
    }
  }
}
