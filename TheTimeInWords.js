process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function timeInWords(h, m) {
    // Complete this function
    var hour_table = {1: "one",
                2: "two",
                3: "three",
                4: "four",
                5: "five",
                6: "six",
                7: "seven",
                8: "eight",
                9: "nine",
                10: "ten",
                11: "eleven",
                12: "twelve",
                13: "one"};
    
    
    var minute_table = {1: "one",
                2: "two",
                3: "three",
                4: "four",
                5: "five",
                6: "six",
                7: "seven",
                8: "eight",
                9: "nine",
                10: "ten",
                11: "eleven",
                12: "twelve",
                13: "thirteen",
                14: "fourteen",
                15: "quarter",
                16: "sixteen",
                17: "seventeen",
                18: "eighteen",
                19: "nineteen",
                20: "twenty",
                21: "twenty one",
                22: "twenty two",
                23: "twenty three",
                24: "twenty four",
                25: "twenty five",
                26: "twenty six",
                27: "twenty seven",
                28: "twenty eight",
                29: "twenty nine",
                30: "half"};
    
    var hour = Number(h);
    
    var minute = Number(m);
    if(minute == 0){
        var s = hour_table[hour] + " o' clock";
        return s;
    }
    
    if(minute >= 1 && minute <= 30)
    {
        var s = "";
        if(minute == 1){
            s += "one minute past " + hour_table[hour];
            return s;
        }
        
        if(minute == 15){
            s += "quarter past " + hour_table[hour];
            return s;
        }
        
        if(minute == 30){
            s += "half past " + hour_table[hour];
            return s;
        }
        
        s += minute_table[minute] + " minutes past " + hour_table[hour];
        return s;
    }
    
    var m_minute = 60 - minute;
    

    
    var s = "";
    
    if(m_minute == 1){
        s += "one minute to " + hour_table[hour + 1];
        return s;
    }
    
    if(m_minute == 15){
        s += "quarter to " + hour_table[hour + 1];
        return s;
    }
    
    s += minute_table[m_minute] + " minutes to " + hour_table[hour + 1];
    return s;
    
    
}

function main() {
    var h = parseInt(readLine());
    var m = parseInt(readLine());
    var result = timeInWords(h, m);
    process.stdout.write("" + result + "\n");

}


