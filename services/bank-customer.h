#include <stdio.h>
#include <stdlib.h>

char DB_NAME[50] = "database/bank-customers.data";
char DB_TRANSFER_NAME[50] = "database/bank-customers-transfer.data";

struct CustomerStruct
{
  int id;
  char nome[255];
  char cpf[11];
} typedef Customer;

void createCustomerDb()
{
  FILE *db = fopen(DB_NAME, "a+");
  fclose(db);
}

void createCustomer()
{
  Customer cliente;
  FILE *database = fopen(DB_NAME, "a+");

  cliente.id = rand();

  printf("Insira o nome completo do cliente: ");
  scanf("%s", cliente.nome);

  printf("Insira o CPF do cliente (apenas os números): ");
  scanf("%s", cliente.cpf);

  fprintf(database, "%d %s %s \n", cliente.id, cliente.nome, cliente.cpf);
  fclose(database);
}

void editCustomer()
{
  FILE *db = fopen(DB_NAME, "r");
  FILE *db_tmp = fopen(DB_TRANSFER_NAME, "w");
  Customer cliente;

  printf("Id do cliente que deve ser editado: ");
  scanf("%d", &cliente.id);

  printf("Insira o nome completo do cliente: ");
  scanf("%s", cliente.nome);

  printf("Insira o CPF do cliente (apenas os números): ");
  scanf("%s", cliente.cpf);

  int id;
  char nome[255];
  char cpf[11];

  while (fscanf(db, "%d %s %s", &id, nome, cpf) != -1)
  {
    if (id == cliente.id)
    {
      fprintf(db_tmp, "%d %s %s \n", cliente.id, cliente.nome, cliente.cpf);
      continue;
    }

    fprintf(db_tmp, "%d %s %s \n", id, nome, cpf);
  }

  fclose(db);
  fclose(db_tmp);
  remove(DB_NAME);
  rename(DB_TRANSFER_NAME, DB_NAME);
}

void deleteCustomer()
{
  FILE *db = fopen(DB_NAME, "r");
  FILE *db_tmp = fopen(DB_TRANSFER_NAME, "w");

  int clienteToDelete = -1;

  printf("Id do cliente que deve ser deletado: ");
  scanf("%d", &clienteToDelete);

  int id;
  char nome[255];
  char cpf[11];

  while (fscanf(db, "%d %s %s", &id, nome, cpf) != -1)
  {
    if (id == clienteToDelete)
    {
      printf("ID: %d | Nome: %s  | CPF: %s  \n", id, nome, cpf);
      continue;
    }

    fprintf(db_tmp, "%d %s %s \n", id, nome, cpf);
  }

  fclose(db);
  fclose(db_tmp);
  remove(DB_NAME);
  rename(DB_TRANSFER_NAME, DB_NAME);
}

void listCustomers()
{
  FILE *db = fopen(DB_NAME, "r");

  int id;
  char nome[255];
  char cpf[11];

  while (fscanf(db, "%d %s %s", &id, nome, cpf) != -1)
  {
    printf("ID: %d | Nome: %s  | CPF: %s  \n", id, nome, cpf);
  }

  fclose(db);
}