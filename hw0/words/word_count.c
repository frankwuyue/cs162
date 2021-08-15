/*

Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

word_count provides lists of words and associated count

Functional methods take the head of a list as first arg.
Mutators take a reference to a list as first arg.
*/

#include "word_count.h"

/* Basic utililties */

char* new_string(char* str) { return strcpy((char*)malloc(strlen(str) + 1), str); }

void init_words(WordCount** wclist) {
  /* Initialize word count.  */
  *wclist = NULL;
}

size_t len_words(WordCount* wchead) {
  size_t len = strlen(wchead->word);
  return len;
}

void print(WordCount* word_count) {
  if (word_count == NULL) {
    printf("WordCount is null\n");
  } else {
    printf("WordCount is word: %s, count: %i\n", word_count->word, word_count->count);
  }
}

WordCount* find_word(WordCount* wchead, char* word) {
  /* Return count for word, if it exists */
  WordCount* wc;
  for (wc = wchead; wc; wc = wc->next) {
    // printf("inside loop:");
    // print(wc);
    if (strcmp(wc->word, word) == 0) {
      return wc;
    }
  }
  return NULL;
}

void add_word(WordCount** wclist, char* word) {
  // printf("0-0\n");
  // print(*wclist);
  /* If word is present in word_counts list, increment the count, otw insert with count 1. */
  WordCount* wc = find_word(*wclist, word);
  // printf("0-1\n");
  // printf("find word:\n");
  // print(wc);
  if (wc == NULL) {
    // printf("0-2\n");
    WordCount* new_count = NULL;
    new_count = (WordCount*)malloc(sizeof(WordCount));
    new_count->count = 1;
    new_count->word = new_string(word);
    new_count->next = NULL;
    // {new_string(word), 1, NULL};
    // printf("0-3\n");
    if (*wclist == NULL) {
      *wclist = new_count;
    } else {
      // printf("0-4\n");
      WordCount* wc_i;
      for (wc_i = *wclist; wc_i; wc_i = wc_i->next) {
        // print(wc_i);
        // printf("next wordcount:");
        // print(wc_i->next);
        if (wc_i->next == NULL) {
          wc_i->next = new_count;
          break;
        }
      }
    }
    // printf("0-5\n");
    // print(*wclist);
  } else {
    wc->count++;
  }
}

void fprint_words(WordCount* wchead, FILE* ofile) {
  /* print word counts to a file */
  WordCount* wc;
  for (wc = wchead; wc; wc = wc->next) {
    fprintf(ofile, "%i\t%s\n", wc->count, wc->word);
  }
}
