const federal = [
    [50197, 0.15],
    [50195, 0.205],
    [55233, 0.26],
    [66083, 0.29],
    [0.33]
]

const federalMax = 0.33;

const alberta = [
    [131220, 0.1],
    [26344, 0.12],
    [52488, 0.13],
    [104976, 0.14]
]

const albertaMax = 0.15;

function taxCalculator(income, province, maxProvince){

    let currentBracket = 0;
    let currentIncome = income;
    let owedTax = 0;

    while(true) {

        if(currentBracket == province.length){
            owedTax += currentIncome * maxProvince;
            break;
        }
        
        if(currentIncome <= province[currentBracket][0]){
            owedTax += currentIncome * province[currentBracket][1];
            break;
        }

        owedTax += province[currentBracket][1] * province[currentBracket][0];
        currentIncome -= province[currentBracket][0];
        currentBracket ++;

    }

    return owedTax;

}