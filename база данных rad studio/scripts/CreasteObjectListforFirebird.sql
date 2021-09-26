CREATE TABLE ObjectList
(
MID_OBJECT BIGINT NOT NULL,     //   код метаобъекта  --   метакод
ID_OBJECT BIGINT NOT NULL,      //   код объекта
CODE_TYPE BIGINT NOT NULL,      //   код типа объекта
NAME_OBJECT VARCHAR(255) NOT NULL,    //    имя объекта
CONSTRAINT PK_ListTypeObjectS PRIMARY KEY (MID_OBJECT)
)
