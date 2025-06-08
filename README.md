🐉 Dungeon Adventure Game – OOP Extension<br>
Welcome to the extended version of the Dungeon Adventure game! This C++ project demonstrates object-oriented programming concepts through an interactive text-based adventure with enemies, puzzles, NPCs, and a final boss battle against a dragon.

🎮 Features
🧙‍♂️ Player can navigate through multiple rooms<br>
🕸️ Solve a 4x4 N-Queen Puzzle Grid in the dark corridor<br>
🐙 Fight Quatro-Otopus, a multi-tentacled enemy<br>
🧙‍♂️ Meet Mario the NPC, who gives helpful items and a mini spell challenge<br>
🐉 Battle or outsmart the Final Dragon Boss using sword, shield, or magic potion<br>
🪙 Collect treasures, take damage, and manage inventory<br>
💡 Game includes creative ASCII art, logic puzzles, and inventory mechanics<br>
HOW TO BUILD:
cd build<br>
rm -rf *<br>
cmake ..<br>
ninja<br>
./game.exe<br>

⚠️ Make sure you have CMake and Ninja installed.

🧩 Highlighted Puzzle – Dark Corridor Grid
You must cross a 4x4 grid by stepping on safe tiles only. A tile is considered safe if placing a queen there doesn't attack any previous queens (based on N-Queen constraints).

Failure to pick a safe tile results in health loss. Solve all 4 steps to proceed!

🧠 Concepts Used<br>
C++ OOP: Classes (Player, Enemy, Treasure, etc.)<br>
Vectors, STL usage<br>
Input/output handling<br>
Game state management<br>
Randomized attacks using rand()<br>
ASCII art and creative storytelling<br>
Logic puzzles (N-Queens)
