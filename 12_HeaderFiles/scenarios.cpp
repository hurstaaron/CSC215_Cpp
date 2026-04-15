// FUNCTIONS INCLUDED IN THE FILE:
//   grimDarkSetting() — Opening scene, first choice
//   theChapel()       — Ruins path, second choice
//   listeningPaths()  — Forest path, second choice

// Include scenarios.h, encounters.h, and utilities.h
#include "scenarios.h"
#include "encounters.h"
#include "utilities.h"

// INCLUDE STANDARD LIBRARIES
#include <iostream>     
#include <string>      

using namespace std; // Helps avoid typing std:: all the time

// === SCENARIO 1: grimDarkSetting ===
string grimDarkSetting(string name) {

    cout << "\nThe night is a wound across the sky, stitched with cold stars "
         << "and the promise of something watching.\n"
         << "You wake in a gutter of black mud beside a road of ancient stones, "
         << "slick as old bones. Ahead, the ruins\n"
         << "of Kareth Vane rise like broken teeth. Behind you, the forest "
         << "presses close: the Wyrmwood, where trees\n"
         << "grow in spirals as if listening to secrets.\n\n";

    cout << "A bell tolls from the ruins; slow, wrong, and far too close for "
         << "its distance. Each note vibrates in your\n"
         << "ribs like a remembered sin. Your hands are empty, but your name "
         << "feels heavy, as if it once belonged to someone braver.\n\n"
         << "A raven lands on a milestone and speaks with a human tongue:\n\n";

    // PLAYER CHOICE: Ruins or Forest
    string prompt = "\"Choose quickly. The dead are impatient.\"\n\n"
                    "   [A] Approach the ruins of Kareth Vane\n"
                    "   [B] Enter the Wyrmwood and follow the whispering trees\n\n"
                    "   Your choice: ";

    char choice = getValidChoice(prompt, 'A', 'B'); // validation function from utilities.cpp

    // Route the player to the appropriate scenario based on their choice
    if (choice == 'A') {
        theChapel();          // Player chose the ruins — head to Scenario 2
    }
    else {
        listeningPaths();     // Player chose the forest — head to Scenario 3
    }

    // Return a transition message displayed in main() 
    return "\nThe story of " + name + " echoes through WhisperingToll...\n\n"; // (Cool UX)
}

// === SCENARIO 2: theChapel ===
// PURPOSE: The player has entered the ruins of Kareth Vane.
void theChapel() {

    cout << "\n\nKareth Vane is quieter than it should be. Not peaceful... "
         << "just held. The air smells of soot, dried blood,\n"
         << "and rain that never arrived. You push through a shattered "
         << "archway into a chapel whose roof has collapsed,\n"
         << "leaving the altar open to the sky. Candles burn anyway, "
         << "hundreds of them standing in melted ranks across\n"
         << "the stone. Their flames do not flicker. They do not bow to wind. "
         << "They burn like vows made under duress.\n\n";

    cout << "At the altar, a stone saint has been carved without eyes. "
         << "Someone has placed fresh teeth in the empty\n"
         << "sockets, small and human. A figure kneels with its back to you, "
         << "draped in mourning cloth. When it turns,\n"
         << "you see a face you recognize from childhood nightmares: "
         << "the Pale Confessor, mouth stitched shut with\n"
         << "silver wire. It raises a hand and points to two offerings "
         << "laid before the altar:\n\n"
         << "   * A tarnished iron reliquary that hums faintly, "
         << "as if something inside wants out.\n"
         << "   * A black ink-stained oathscroll, already bearing your "
         << "signature in a handwriting you don't remember.\n\n"
         << "The Confessor's fingers twitch. "
         << "The candles lean toward you like eager witnesses.\n\n";

    // PLAYER CHOICE: Oathscroll or Reliquary
    string prompt = "\"Choose quickly. The dead are impatient.\"\n\n"
                    "   [A] Take the oathscroll and read it aloud\n"
                    "   [B] Take the iron reliquary and break its seal\n\n"
                    "   Your choice: ";

    char choice = getValidChoice(prompt, 'A', 'B'); // validation function from utilities.cpp

    // Route to the next encounter based on the player's decision
    if (choice == 'A') {
        priceForSpeaking();   // The oath consumes the player — death scene
    }
    else {
        bossBattle();         // Breaking the seal unleashes the final boss
    }
}


// === SCENARIO 3: listeningPaths ===
void listeningPaths() {

    cout << "\n\nThe forest accepts you the way deep water accepts a stone: "
         << "without hesitation, without mercy.\n"
         << "The trees are tall and twisted, bark folded like scar tissue. "
         << "You notice carvings in the trunks... not\n"
         << "runes, not letters, just tally marks in uneven rows, as if "
         << "the forest is counting something it cannot\n"
         << "afford to forget. Your footsteps do not echo. Instead, you hear "
         << "other footsteps matching yours, always\n"
         << "one pace behind.\n\n";

    cout << "Fog coils between the roots. In it, shapes drift, almost human, "
         << "almost familiar, wearing faces that do\n"
         << "not fit them properly. A child's laughter slips through the "
         << "branches, bright and wrong.\n\n"
         << "You come upon a pool as black as ink. Suspended above it, "
         << "hanging from thorn-vines, is a cage of bone.\n"
         << "Inside the cage: a lantern still lit, its flame trembling like "
         << "a fearful heart. Beneath the cage, at the\n"
         << "pool's edge, lies a sword half-buried in moss, its blade "
         << "pitted but real.\n\n"
         << "The air tastes like iron and death. A voice whispers "
         << "behind you...\n\n";

    // PLAYER CHOICE: Sword or Pool
    string prompt = "\"Only one choice will let you escape me.\"\n\n"
                    "   [A] Take the sword and cut down the bone cage lantern\n"
                    "   [B] Kneel and drink from the black pool to see the truth\n\n"
                    "   Your choice: ";

    char choice = getValidChoice(prompt, 'A', 'B'); // validation function from utilities.cpp

    // Route to the next encounter based on the player's decision
    if (choice == 'A') {
        bossBattle();         // Armed with a sword, face the final boss
    }
    else {
        seeTruth();           // Routte to seeTruth()
                            
    }
}
