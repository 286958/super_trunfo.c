# Super Trunfo - Comparações Avançadas em C

Jogo de cartas inspirado no Super Trunfo, onde o jogador compara atributos de países.  
Permite escolher cartas, atributos e jogar múltiplas rodadas.

---

## Funcionalidades

- Escolha de **duas cartas** por rodada.  
- Escolha de **dois atributos diferentes** para comparação.  
- Comparação: **maior valor vence**, exceto **densidade demográfica**, onde **menor vence**.  
- Soma dos atributos e decisão do vencedor da rodada.  
- Tratamento de **empates** corretamente.  
- **Laço de repetição** para jogar múltiplas rodadas.  
- Menus com validação de entradas e bloqueio de opções já escolhidas.  

---

## Atributos disponíveis

1. **População** (milhões)  
2. **Área** (mil km²)  
3. **PIB** (bilhões USD)  
4. **Densidade Demográfica** (hab/km²) — menor é melhor  

---

## Como compilar

Certifique-se de ter o GCC instalado no seu sistema.  
Abra o terminal no diretório do projeto e execute:

```bash
gcc super_trunfo.c -o super_trunfo.exe
