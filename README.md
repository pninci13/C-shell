# Projeto Shell

### $\color{SkyBlue}{Objetivo\}$
* O objetivo deste projeto é criar um shell simples, que conseguisse simular alguns comandos
encontrados em terminais atuais.

Sendo os comandos básicos:
- cd <diretório> - Mudar de diretório
- exit - Sair do shell
- path <diretório>:<diretório>  - Adiciona o diretório ao path de ambiente para setar busca de executavéis.

Comandos extras:
- ls - Lista os arquivos presentes no diretório atual
- ls -a - Lista os arquivos presentes no diretório atual incluindo arquivos ocultos
- ls -l - Lista os aquivos com mais detalhes, mostrando permissões, grupos, tamanho, data de modificação...
- cat <arquivo> - Exibe o conteúdo de um arquivo.
- echo - Printa mensagens ou variavéis.
- pwd - Mostra pro usuário na tela qual o diretório está atualmente.
- help - Mostra comandos disponíveis para o usuário.
- clear - Limpa a tela do shell

### $\color{SkyBlue}{Como\ compilar\ ?\}$

Clone o repositório e salve em algum local em sua máquina.\Depois de salvo e aberto, abra um terminal e digite:\
<table><tr><td>gcc shell.c -o nome_do_outuput</td></tr></table>
<table><tr><td>./nome_do_output</td></tr></table>

Assim que executar, digite "help" para ver os comandos disponíveis no shell.

> [!IMPORTANT]
> Execute o programa em um ambiente Linux ou WSL, em Windows pode causar eventuais problemas.

### $\color{SkyBlue}{Como\ executar\ os\ comandos\?\}$

```bash
1) path <diretório>:<diretório>
2) cd <diretório>
3) ls (Contém as flags -l -a)
4) path /usr/bin  *Para poder executar comandos externos em qualquer caminho*
5) cat <arquivo> ou ser for mais um arquivo cat <arquivo> <arquivo>
6) echo {mensagem} ou {variavél}
```

### $\color{SkyBlue}{Código\}$

* Fizemos as implementações básicas e extras e também adicionamos 2 comandos que não estavam no escopo, para que fosse possível testar os outros comandos de forma eficiente
  e são eles o comando $\color{GreenYellow}{Echo\}$ e $\color{GreenYellow}{Pwd\}$.
- Existem 3 métodos no programa
    - **Main** - Possui o loop infinito para receber comandos do shell, sendo eles built-in ou internos, como cd, path e exit ou utilizando a função de executar comando externo.
      O método faz um processamento dos dados de entrada, ou seja, os comandos digitados pelo usuário, dividindo-os em tokens e são armazenados do vetor de args. E também é feita uma validação na qual vê se o usuário digita um caracter '\n' de nova linha, se sim
      ele é removido.
    - **Executar comandos externos** - Executa comandos que não implementados internamente no shell, ou seja, comandos como echo, ls, cat e outros. E também é feito o uso de processos, ou seja, é criado um processo filho a partir do pai, que executa
       comandos digitados pelo usuário e valida se o comando é conhecido ou não e o processo pai aguarda a finalização da execução dos filhos. Validações como erro de criação de processo também estão sendo feitas.
    - **Help** - Mostra o menu de ajuda

### $\color{SkyBlue}{Autores\}$
1. Julio Moura
2. Pedro Ninci
3. Pedro Bardall
4. Vitor Sardinha
