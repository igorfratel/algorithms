/*
 * @param {string} word
 * @return {number[]}
 */
function buildPartialMatchTable(word) {
    const patternTable = [0]
    let prefixIndex = 0
    let suffixIndex = 1

    while(suffixIndex < word.length) {
        if(word[suffixIndex] === word[prefixIndex]) {
            patternTable[prefixIndex] = suffixIndex + 1
            prefixIndex++
            suffixIndex++
        }
        else if(prefixIndex === 0) {
            patternTable[suffixIndex] = 0
            suffixIndex++
        }
        else {
            prefixIndex = patternTable[prefixIndex - 1]
            
        }
    }

    return patternTable
}

/*
 * @param {string} text
 * @param {string} word
 * @return number
 */
export default function knuthMorrisPratt(text, word) {

    if(word.length === 0) return 0

    let textIndex = 0
    let wordIndex = 0

    const partialMatchTable = buildPartialMatchTable(word)

    while(textIndex < text.length) {
        if(text[textIndex] === word[wordIndex]) {
            if(wordIndex === word.length - 1) 
                return (textIndex - word.length) + 1
            textIndex++
            wordIndex++
        }
        else if(wordIndex > 0) {
            wordIndex = partialMatchTable[wordIndex - 1]
        }
        else textIndex++
    }

    return -1
}
