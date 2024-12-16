#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * Draw the chessboard on screen.
 *
 * @param[in] queens The string representation of the queens
 * @param[in] n      The size of the chessboard
 */
void draw(char queens[], size_t n) {
  cs1010_clear_screen();
  for (size_t i = 0; i < n; i += 1) {
    for (char col = 'a'; col < 'a' + (char)n; col += 1) {
      if (queens[i] == col) {
        putchar('#');
      } else {
        putchar('.');
      }
    }
    putchar('\n');
  }
  usleep(10000);
}

void swap(char a[], size_t i, size_t j) {
  char temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

/**
 * Checks if the queen on curr_row clashes with any queens
 * from curr_row+1 to last_row, inclusive.
 *
 * @param[in] queens   The string representation of the queens.
 * @param[in] curr_row The row where the queen to check for
 *                     clashes is on.
 * @param[in] last_row The last row until which we check for
 *                     clashes.
 *
 * @pre    0 <= curr_row <= last_row
 * @return true if there is a queen that clahes with queen[curr_row]
 *         diagonally false otherwise.
 */
bool has_a_queen_in_diagonal(const char queens[], size_t curr_row,
                             size_t last_row) {
  char curr_col = queens[curr_row];
  char left_col = curr_col - 1;
  char right_col = curr_col + 1;
  for (size_t row = curr_row+1; row <= last_row; row += 1) {
    if (queens[row] == left_col || queens[row] == right_col) {
      return true;
    }
    left_col -= 1;
    right_col += 1;
  }
  return false;
}

/**
 * Checks if any queen from row 0 to last_row (inclusive) that
 * clashes with each other, diagonally.
 *
 * @param[in] queens   The array containing the representation
 *                     of the queens.
 * @param[in] last_row The last row until which we check for clashes.
 *
 * @pre    0 <= last_row <= n-1
 * @return true if there are two queens that clash with each other.
 */
bool threaten_each_other_diagonally(char queens[], size_t last_row) {
  for (size_t curr_row = 0; curr_row <= last_row; curr_row += 1) {
    if (has_a_queen_in_diagonal(queens, curr_row, last_row)) {
      return true;
    }
  }
  return false;
}

/**
 * Fix a[0]..a[k - 1] but permute queens a[k]..a[len - 1]
 * Print out each permutation if valid.
 *
 * @param[in,out] a The array to permute
 * @param[in]     n The size of the array
 * @param[in]     k The starting index at which we will permute
 *
 * @post The string a remains unchanged
 */
bool nqueens(char a[], size_t n, size_t k) {
  if (k == n-1) {
    draw(a, n);
    if (!threaten_each_other_diagonally(a, n - 1)) {
      cs1010_println_string(a);
      return true;
    }
    return false;
  }
  for (size_t i = k; i < n; i+= 1) {
    swap(a, k, i);
    if (!threaten_each_other_diagonally(a, k)) {
      if (nqueens(a, n, k+1)) {
        return true;
      }
    }
    swap(a, i, k);
  }
  return false;
}

int main() {
  size_t n = cs1010_read_size_t();
  char *queens = malloc((n + 1) * sizeof(char));
  queens[0] = 'a';
  for (size_t i = 1; i < n; i += 1) {
    queens[i] = queens[i-1] + 1;
  }
  queens[n] = '\0';
  nqueens(queens, n, 0);
  free(queens);
}
