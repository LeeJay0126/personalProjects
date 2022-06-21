



function listenerY() {

    let zombiesArray = document.querySelectorAll("#zombies > .zombie");

    person.setAttribute("cy", document.querySelector("#sliderY").value);


    for (zombie of zombiesArray) {

        let zombieString = zombie.getAttribute("transform");
        let startPointY = zombieString.indexOf(",")
        let endPointY = zombieString.indexOf(")");
        let tokenY = zombieString.substring(startPointY + 1, endPointY);
        let startPointX = zombieString.indexOf("(")
        let endPointX = zombieString.indexOf(",");
        let tokenX = zombieString.substring(startPointX + 1, endPointX);
      
        

        if (person.getAttribute("cy") - Number(tokenY) > 50 || Number(tokenY) - person.getAttribute("cy") > 50) {
           
            zombie.setAttribute("fill", "black");
        
        } else if(person.getAttribute("cx") - Number(tokenX) > 50 || Number(tokenX) - person.getAttribute("cx") > 50){

            zombie.setAttribute("fill", "black");

        }else {
            zombie.setAttribute("fill", "yellow");
        }
    }


}
function listenerX() {

    let zombiesArray = document.querySelectorAll("#zombies > .zombie");

    person.setAttribute("cx", document.querySelector("#sliderX").value);
   
    for (zombie of zombiesArray) {

        let zombieString = zombie.getAttribute("transform");
        let startPointY = zombieString.indexOf(",")
        let endPointY = zombieString.indexOf(")");
        let tokenY = zombieString.substring(startPointY + 1, endPointY);
        let startPointX = zombieString.indexOf("(")
        let endPointX = zombieString.indexOf(",");
        let tokenX = zombieString.substring(startPointX + 1, endPointX);
      
        

        if (person.getAttribute("cy") - Number(tokenY) > 50 || Number(tokenY) - person.getAttribute("cy") > 50) {
           
            zombie.setAttribute("fill", "black");
        
        } else if(person.getAttribute("cx") - Number(tokenX) > 50 || Number(tokenX) - person.getAttribute("cx") > 50){

            zombie.setAttribute("fill", "black");

        }else {
            zombie.setAttribute("fill", "yellow");
        }
    }

}

