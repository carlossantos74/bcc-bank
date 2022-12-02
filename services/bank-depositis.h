#include <stdio.h>
#include <stdlib.h>

char DB_DEPOSIT_NAME[50] = "database/bank-deposits.data";
char DB_DEPOSIT_TMP_NAME[50] = "database/bank-deposits-transfer.data";

struct DepositStruct
{
  int id;
  float valor;
  int clienteId;
} typedef Deposit;

void createDepositDb()
{
  FILE *db = fopen(DB_DEPOSIT_NAME, "a+");
  fclose(db);
}

void createDeposit()
{
  Deposit deposito;
  FILE *db = fopen(DB_DEPOSIT_NAME, "a+");

  deposito.id = rand();

  printf("Insira o id do cliente que fez o depósito: ");
  scanf("%d", &deposito.clienteId);

  printf("Insira o valor do depósito: ");
  scanf("%f", &deposito.valor);

  fprintf(db, "%d %f %d \n", deposito.id, deposito.valor, deposito.clienteId);
  fclose(db);
}

void listDeposits()
{
  FILE *db = fopen(DB_DEPOSIT_NAME, "r");

  int id;
  float valor;
  int clienteId;

  while (fscanf(db, "%d %f %d", &id, &valor, &clienteId) != -1)
  {
    printf("ID: %d | Valor: %f  | Cliente: %d  \n", id, valor, clienteId);
  }

  fclose(db);
}

void deleteDeposit()
{
  FILE *db = fopen(DB_DEPOSIT_NAME, "r");
  FILE *db_tmp = fopen(DB_DEPOSIT_TMP_NAME, "w");

  int depositToDelete = -1;

  printf("Id do depósito que deve ser deletado: ");
  scanf("%d", &depositToDelete);

  int id;
  float valor;
  int clienteId;

  while (fscanf(db, "%d %f %d", &id, &valor, &clienteId) != -1)
  {
    if (id == depositToDelete)
    {
      printf("ID: %d | Valor: %f  | Cliente: %d  \n", id, valor, clienteId);
      continue;
    }

    fprintf(db_tmp, "%d %f %d \n", id, valor, clienteId);
  }

  fclose(db);
  fclose(db_tmp);
  remove(DB_DEPOSIT_NAME);
  rename(DB_DEPOSIT_TMP_NAME, DB_DEPOSIT_NAME);
}