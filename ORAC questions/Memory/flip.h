#ifdef __cplusplus
extern "C" {
#endif

/**
 * Problem: Memory
 *
 * Interface for interacting with judging software.
 *
 * See problem description for usage.
 */

/**
 * Returns the initial number of cards
 */
int getC(void);

/**
 * Flips over the specified card, and returns the letter written on that card.
 */
char faceup(int card);

#ifdef __cplusplus
}
#endif

