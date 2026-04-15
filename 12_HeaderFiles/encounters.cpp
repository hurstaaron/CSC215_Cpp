#include "encounters.h"
#include "utilities.h"     
#include "scenarios.h"     
#include <iostream>  

using namespace std;


// SCENARIO 2A: priceForSpeaking
void priceForSpeaking() {

    cout << "\n\nYour voice should be your own. It isn't.\n\n"
         << "The first words you read are not words at all — they are hooks. "
         << "They sink into your throat, your lungs,\n"
         << "your marrow. The chapel exhales, satisfied. The candles flare "
         << "blue, and the stitched mouth of the\n"
         << "Confessor smiles without moving.\n\n"
         << "Your tongue blackens into ash. Your eyes fill with candlewax. "
         << "You try to scream, but the oath is already\n"
         << "doing the screaming for you. Above, the open sky bends inward "
         << "like a lid closing on a coffin.\n\n"
         << "The last thing you feel is the gentle pressure of a hand on "
         << "your shoulder — comforting, almost kind —\n"
         << "before the chapel swallows your name whole.\n\n";

    playAgain(theChapel);
}


// === SCENARIO 3B: seeTruth ===
void seeTruth() {

    cout << "\n\nYou kneel at the edge of the black pool. The surface is "
         << "perfectly still, like glass poured over an\n"
         << "abyss. Your reflection stares back, but it is not mirroring "
         << "you. It is waiting for you.\n\n"

         << "You drink.\n\n"

         << "The taste is not water. It is memory — thick, bitter, and "
         << "ancient. The forest around you dissolves\n"
         << "like wet parchment, and suddenly you are everywhere at once.\n\n";

    cout << "You see WhisperingToll as it truly is: not a town, but a "
         << "mouth. A slow, patient hunger that wears\n"
         << "buildings like teeth and roads like a tongue. Every traveler "
         << "who wandered in — every name carved on\n"
         << "milestones, every prayer whispered in the chapel — was "
         << "swallowed whole. The tally marks on the trees\n"
         << "were not counting days. They were counting you. All of you. "
         << "Every version of you that came before.\n\n";

    cout << "You see the raven that spoke at the milestone. You see the "
         << "Pale Confessor kneeling in its chapel.\n"
         << "You see the Thorn-Crowned Hunger sitting on its throne of "
         << "root and bone. They are the same thing.\n"
         << "Three faces of one endless appetite, and you have been "
         << "walking its digestive tract since you woke\n"
         << "in that gutter of black mud.\n\n";


    cout << "The truth fills you like floodwater fills a basement — "
         << "fast, cold, and without air. Your mind\n"
         << "cracks like old pottery. Your body kneels at the pool's edge, "
         << "but you are no longer inside it.\n\n"
         << "The forest leans in. The tally marks on the nearest tree "
         << "shift, and a new mark appears — yours.\n"
         << "The pool's surface ripples once, then goes still again, "
         << "ready for the next traveler who thinks\n"
         << "that knowing the truth is the same as surviving it.\n\n";

    playAgain(theChapel);
}


// === FINAL ENCOUNTER: bossBattle ===
void bossBattle() {

    cout << "\n\nThe world narrows into a single place, as if reality "
         << "itself is bracing for impact.\n"
         << "You stand in a circular ruin — an arena of broken pillars "
         << "and wet stone — beneath a sky that churns\n"
         << "like a bruise. In the center squats a throne grown from "
         << "twisted roots and fused bone.\n\n";

    cout << "Upon it sits the Thorn-Crowned Hunger, the thing that has "
         << "been wearing the night like a cloak.\n"
         << "It rises. Not quickly — never hurried — because it has "
         << "nowhere to be except inside your ending.\n\n"
         << "Its body is a cathedral of rot and regalia: ribs plated "
         << "with black iron, a crown of thorns hammered\n"
         << "through living flesh, and a face that shifts between "
         << "beautiful and unbearable. When it speaks, the\n"
         << "sound is not heard so much as remembered.\n\n";

    cout << "\"You came,\" it says, its voice the sound of roots breaking "
         << "stone. \"You ALWAYS come.\"\n\n"
         << "The fight begins the moment you understand you are already "
         << "losing. Your strikes feel like arguments\n"
         << "made to a judge who stopped caring centuries ago. Your breath "
         << "burns. Your arms tremble. Your vision\n"
         << "tunnels. Still, you remain standing.\n\n"
         << "The Hunger leans close. You smell grave-dirt and sweet "
         << "incense.\n\n"
         << "Rally, little ember... or run.\"\n\n";


    string prompt = "   [A] Rally — stand your ground and fight\n"
                    "   [B] Run — flee into the darkness and never look back\n\n"
                    "   Your choice: ";

    
    char choice = getValidChoice(prompt, 'A', 'B'); // Use the shared validation function

    //OUTCOME A: FIGHT (DEATH)
    if (choice == 'A') {
        cout << "\n\nYou plant your feet. You scream defiance into the "
             << "bruised sky. For one heartbeat — just one —\n"
             << "the Thorn-Crowned Hunger pauses, as if it has not seen "
             << "this particular flavor of courage in\n"
             << "a very long time.\n\n"

             << "Then it moves.\n\n"

             << "Not fast. Not slow. It moves like gravity — inevitable, "
             << "impersonal, and absolute. Its hand\n"
             << "passes through your chest the way a hand passes through "
             << "smoke. You feel your ribs fold inward\n"
             << "like closing wings. Your blood runs cold, then hot, then "
             << "not at all.\n\n"

             << "The Hunger catches you as you fall — almost gently — and "
             << "lowers you to the wet stone.\n"
             << "\"Brave,\" it whispers, and the word sounds like a "
             << "headstone being carved. \"But bravery is just\n"
             << "a louder way to die.\"\n\n"

             << "The thorns of its crown drip something dark onto your "
             << "face. The last thing you see is the sky\n"
             << "above, still churning, still watching, as WhisperingToll "
             << "adds your name to its long, long count.\n\n";

        playAgain(theChapel);
    }

    // OUTCOME B: FLEE (SURVIVAL — THE ONLY WIN CONDITION)
    else {
        cout << "\n\nYou run.\n\n"

             << "Not heroically. Not with a battle cry or a defiant glare. "
             << "You turn and you RUN, and every instinct\n"
             << "you have screams that this is the first honest thing "
             << "you have done since you woke in that gutter.\n\n"

             << "The Hunger laughs behind you — a sound like a cathedral "
             << "collapsing in slow motion — but it does\n"
             << "not follow. It does not need to. It has patience measured "
             << "in centuries. It will wait.\n\n"

             << "You crash through the Wyrmwood, branches tearing at your "
             << "skin, roots grasping at your ankles.\n"
             << "The tally marks on the trees blur past you. The fog "
             << "reaches, but you are faster — barely,\n"
             << "impossibly faster.\n\n"

             << "Then: dawn.\n\n"

             << "Thin and pale as a dying candle, but real. The trees "
             << "thin. The road appears beneath your feet,\n"
             << "cracked and ancient but leading AWAY. The bell of Kareth "
             << "Vane tolls one final time behind you,\n"
             << "distant now, disappointed.\n\n"

             << "You do not look back. You will never look back.\n\n"

             << "   ============================================\n"
             << "   ||   YOU HAVE ESCAPED WHISPERINGTOLL.     ||\n"
             << "   ||                                        ||\n"
             << "   ||   Some battles are won by surviving.   ||\n"
             << "   ||   Some victories taste like running.   ||\n"
             << "   ||   You are alive. That is enough.       ||\n"
             << "   ============================================\n\n"

             << "Thank you for playing.\n\n";

    }
}
