
/**
 * @function includes
 * @description - Busca um elemento dentro de um array
 * @param array - Array que o item vai ser procurado
 * @param element Item que vai ser buscado dentro do array
 * @returns 1 quando encontrar, se não eonctrar retorna 0
 */
int includes(int array[], int element)
{
  int length = sizeof array;
  int isElementPresent = 0;

  for (int i = 0; i < length; i++)
  {
    if (array[i] == element)
    {
      isElementPresent = 1;
      break;
    }
  }

  return isElementPresent;
}

/**
 * @function createFile
 * @param {char} dbname - nome do banco que vai ser criado.
 * @description - Cria o arquivo para persistir os dados
 * @returns void
 */
void createFile(char *dbname)
{
  FILE *db = fopen(dbname, "a+");
  fclose(db);
}