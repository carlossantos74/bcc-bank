#include <stdio.h>
#include "util/helpers.h"
#include "util/banner.h"
#include "services/bank-customer.h"

int menu()
{
  int options[] = {0, 1, 2, 3, 4};
  int option = -1;

  printf("Selecione a opção desejada \n");
  printf("1 - Adicionar cliente \n");
  printf("2 - Editar cliente \n");
  printf("3 - Listar clientes \n");
  printf("4 - Deletar cliente \n");
  printf("0 - Sair \n");
  scanf("%d", &option);

  if (!includes(options, option))
  {
    menu();
  }

  return option;
}

void main()
{
  createCustomerDb();

  banner();
  int option = menu();

  switch (option)
  {
  case 1:
    createCustomer();
    break;
  case 2:
    editCustomer();
    break;
  case 3:
    listCustomers();
    break;
  case 4:
    deleteCustomer();
    break;
  default:
    break;
  }

  if (option == 0)
    return;

  // option = menu();
}