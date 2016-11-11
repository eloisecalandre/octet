Eloise Calandre

Evaluation: invaderers


In the first lecturer we were set the basic task of changing the size and number of sprites within the game. 
I began by reading the C++ tutorials online to understand the principals of coding. The first changes I made were to 
alter the size of the sprites by increases the number value in width and height (within the perimeters of 0-1), and decreasing 
number of sprites by reducing the number for the columns (I think I left the original amount of rows).

I continued to read up on the C++ website and made some test notes in place to try to show my understanding of the exisitng code.

I wanted to change the colours within the game and it was suggested that I should hack the texture shader. 
At this point I became stuck, as I tried various code changes (inline with my online research) and they all broke the game. 
Then I got together with Matthew Duddington and he helped me to change the colour overall within the texture shader. 
However, this was not straight foward for Matthew either. He could see that I had begun as he would have, by introducing a new 'vec4' 
and placing new colour information in for RGB + opacity (using 0-1 conversions for the RGB by divided the chosen colour channels each by 255).

When Matthew and I worked together through these steps the game debugger encounters errors and the game wouldn't load properly. 
Matthew then helped me to change the uniform colour a different, more complex way. He worked out the solution,
then asked me to repeat the steps with text only (dummy) commands to show that I had understood - these are the 'cake' 
additions to the coding.

The solution to affect uniform colour change via the texture shader took 4 steps to complete: 

STEP 1
introduce the 'uniform vec4 colour' 
uniform because the uniform variable applies the same value to multiple vertices, thus creating a uniform 
change throughout the game, and uniforms can be accessed from any shader.
vec4 is the declaration of the type .......
colour is the name chosen to identify the action for the coder(s)
This uniform command must be placed within the structure of the code, therefore withi the open and close parenthesise 
and before the 'main' command, because c++ reads downwards, therefore 'main' should remain at the end.

STEP 2
create a flag. 
By placing a new graphics language unsigned integer with a chosen name (a name that we can identify with the rest of this process)
in the public section of the texture shader, we create a reference point within the code that we can use to 
point the 'uniform vec4' to the right place.

STEP 3
give the uniform a location and attach it to the flag that we have created, using the following code:
colourIndex_ = glGetUniformLocation(program(), "colour");
The 'get uniform location' command links the graphics language unsigned integer (GLuint) to the uniform colour

STEP 4
Transfer the original to the uniform and set the colour using RGB converted to 0-1 values and setting the opacity with 0-1.

This process gave a blue tint to the whole game, which of course does not affect the black, but changes all white areas 
to the chosen colour.

Continuing on my own, I was interested in changing the manifestation of the sprites - I discovered that the there is an assets folder
containing image gifs, which made it easy for me to create new pixel art images in photoshop. I opened each gif file
and used the existing pixel dimensions to create my own files, and gave these the same names as the orginals. 
This meant that the code would look for the original file names to load within the game, and my new image gifs would appear in place 
of the other images (I kept the original files by renaming them with a different name so that the game would not load these).

The new images changed the invaderers to vampire invaderers, who drip deadly blood instead of dropping bombs.
The ship was replace by a severed demon head, spewing pea soup (cliche ref: The Exorcist) instead of firing missiles.

However, I then needed to changed the uniform colour again, to support the new look of the game. This time is was easy.
I could just re-programme the RGB and opacity numbers to create the yellow colour instead of the blue within the texture shader.

I also changed the text of the 'score' by using the find command to locate the text within the origninal code.

Next I wanted to change the sound files and planned to introduce a third with new coding. The original sounds are made using two .wav files 
in the assets folder. I created new sound files to replace these, but encountered a problem. I gave my sound files the same
names as the originals 'whoosh' and 'bang', but when the game loaded it created a weird reverb pitch delay on my sounds. 
I checked the code for 'pitch' specifications, but didn't find anything. I thought there may be something in the external dependancies folder
but was not sure. I then thought it would be to do with the length of the file. 
The original files are at a length of 0 seconds, and mine were 1 and 2 seconds, so I thought may they had somehow been tiled by the code
if it anticpated a file set at a specific length. I created a new test sound file at 0 seconds, but it had the same problem upon load. 
I tried to cheat by created a sound file with a higher pitch so that it would play back at the desired pitch in game, but that sounded
aweful, therefore I restored the original files instead and decided to try something else.

I went through all the coding and looked for more interesting things to change, then changed the velocity to make the invaderers faster
and set the background colour to midnight blue.

Then when studying the code more closely I realised that the code specifies that the sound files are 16 bit MONO (and my recordings were 
64 bit STEREO). At first I tested whether I could change the code to accept 64bit Stereo, but that just corrupted the sound altogether, 
so instead I used Abobe Audition software to convert my files to the right format to match the original - success at last!

This enabled me to continue with my initial plan to introduce a third sound into the game play. I carefully read and made notes on all the places 
that 'whoosh' and 'bang' occured in the coding and could see how they were being orchestrated. 
I wanted to leave the 'whoosh' coding in place for dropping bombs (now vampire blood) with my new sound file in place of the original in the assets folder.
And keep 'bang' for both "when we are hit" and "when we hit an enemy" as originally coded, but with my new sound file in plance of the original in the 
assets folder.
The third sound is for firing a missile, now peasoup vomit, to give it some autonomy. Therefore I folded the same method that I could see, 
which took three steps:
STEP 1
first introducting a new Aluint command with 'peasoup' as the choosen name, at the same point as the first two Aluint commands for 'whoosh' and 'bang'.
STEP 2
with the "Find A Missile" subcommand of the "Fire button", I replaced 'whoosh' with my own 'peasoup' to point the alSourcei command to the 
correct source (my 'peasoup')
STEP 3
introducing and defining the new source file in the assets folder, I used the same code as used for the 'whoosh' and 'bang' assets.
This was successful. we now have three distinct sounds in use.

Here is the YouTube link:
https://youtu.be/hzyrp2IcZpY

and embed code:
<iframe width="560" height="315" src="https://www.youtube.com/embed/hzyrp2IcZpY" frameborder="0" allowfullscreen></iframe>
