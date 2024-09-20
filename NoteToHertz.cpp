
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;


/*
Format:
 Input:
 1st line is #of input lines after this
 Next set of lines contain the following format:
 [Note (Upper Case Letter)] [Duration (QuarterNote=1)] [Octave (A4-B4)=0]

 Important Notes: If note has flat or sharp, enter after the note without space
    Ex. Eb, Fs

 You can change the beats per minute by changing the beat per minute command: default 60
 scale determines how much sticatto is on a note
 */

//Converts note to position relative to A4
double convert(char note, char oct, int octave) {
    if (note == 'r' || note == 'R') {
        return 50;
    }
    int octs = oct == ' ' ? 0 : oct == 'b' ? -1 : 1;

    switch (note) {
        case 'A': return octs + octave * 12 + 0;
        case 'B': return octs + octave * 12 + 2;
        case 'C': return octs + octave * 12 + 3;
        case 'D': return octs + octave * 12 + 5;
        case 'E': return octs + octave * 12 + 7;
        case 'F': return octs + octave * 12 + 8;
        case 'G': return octs + octave * 12 + 10;
        default: return note;
    }

    return 0;
}

int main() {
    //takes input from music.txt file
    ifstream fin ("music.txt");

    //outputs code on desmoss.txt file
    ofstream fout ("desmoss.txt");

    double bpm = 60;
    bpm = bpm / 60;
    vector<pair<double, double>> song;
    int lens = 0;
    fin >> lens;
    double pos = 0;
    for (int i = 0; i < lens; i++) {
        //note has note
        // b is length of note (0.25 = sixteenth, 0.5 = eight, 1=quarter, 2 = half, 4=whole)
        //c has octave
        string note;
        double b, c;
        fin >> note >> b >> c;

        note = note + " ";
        //(A4=0) (rest = 50)
        double rest = 50;
        double a = convert(note[0], note[1], c);
        if (a == rest) {
            pos += b;
            continue;
        }
        b = b / bpm / 2; //converts length of note to seconds
        double scale = 0.95; //scale determines how much sticatto should be applied to a note
        fout << "{" << pos << " <= a < " << pos + b * scale << ": tone(" << 440*pow(2,a/12) << "}" << endl;
        pos = pos + b;
    }
}
