// Function Mode adapted from: http://rosettacode.org/wiki/Averages/Mode#JavaScript

function Mode(ary) {
    let [counter, mode, max, index, i] = [{}, ary[0], 0, 0, 0]
    for (let num of ary) {
        if (!(num in counter))
            counter[num] = 0
        counter[num]++

        if (counter[num] > max)
            [mode, max, index] = [num, counter[num], i]
        i++
    }
    return [max, index]
}

function solution(A) {
    const mode = Mode(A)
    return mode[0] > (A.length / 2) ? mode[1] : -1
}