CREATE TABLE ObjectList
(
MID_OBJECT BIGINT NOT NULL,     //   ��� �����������  --   �������
ID_OBJECT BIGINT NOT NULL,      //   ��� �������
CODE_TYPE BIGINT NOT NULL,      //   ��� ���� �������
NAME_OBJECT VARCHAR(255) NOT NULL,    //    ��� �������
CONSTRAINT PK_ListTypeObjectS PRIMARY KEY (MID_OBJECT)
)
