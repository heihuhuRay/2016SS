// JavaScript Document

// config
var currentLoop = 0;
var totalLoops = 0;
var endFrameDelay = 4;
var useReplayBtn = false;

// content
var container;
var bgImage;
var copy_frame01a;
var copy_frame01b;
var copy_frame01c;
var copy_frame01d;
var copy_frame02;
var copy_frame03;
var logoExpedia;
var btnReplay;
var ctaBtn;
var exitBtn;

var frameWaitTimer;


startAd = function()
{
    // content
    container = document.getElementById("container");
    bgImage = document.getElementById("bgImage");
    logoExpedia = document.getElementById("logoExpedia");
    copy_frame01a = document.getElementById("copy_frame01a");
    copy_frame01b = document.getElementById("copy_frame01b");
    copy_frame01c = document.getElementById("copy_frame01c");
    copy_frame01d = document.getElementById("copy_frame01d");
    copy_frame02 = document.getElementById("copy_frame02");
    copy_frame03 = document.getElementById("copy_frame03");
    ctaBtn = document.getElementById("ctaBtn");
    btnReplay = document.getElementById("btnReplay");
    exitBtn = document.getElementById("exitBtn");

    // set image urls for banner. We do this in JS so its not inclued in polite load.
    bgImage.src = "images/background.jpg";
    copy_frame02.src = "images/copy_frame02.png";
    copy_frame03.src = "images/copy_frame03.png";
    ctaBtn.src = "images/ctaBtn.png";

    // activate btns
    exitBtn.addEventListener('click', exitBtn_clickHandler, false);

    if(useReplayBtn)
    {
        btnReplay.addEventListener('click', btnReplay_clickHandler, false);
        btnReplay.addEventListener("mouseover", btnReplay_overHandler, false);
        btnReplay.addEventListener("mouseout", btnReplay_outHandler, false);
    }
    
    // show Ad
    container.style.display = "block";

    showFrame(1);
}


function exitBtn_clickHandler() 
{
    Enabler.exit("ExitClickthrough");
}

function btnReplay_clickHandler() 
{
    showFrame(1);
    console.log("btnReplay_clickHandler");
}

function btnReplay_overHandler() 
{
    //console.log("btnReplay_overHandler");
    setClass(btnReplay, 0, "replayOver");
}

function btnReplay_outHandler() 
{
    //console.log("btnReplay_outHandler");
    setClass(btnReplay, 0, "replayOff");
}



/**
 * set class
*/
setClass = function(element, time, state) {
   var delay = time*1000;
    window.setTimeout(function(){
        element.className = state;
    }, delay);
}


var holdFrame = function(frame, time) {
    var delay = time*1000;
    frameWaitTimer = window.setTimeout(function(){showFrame(frame);}, delay);
}


/**
 * switch statement for animating ad
 */
function showFrame(id)
{
    //console.log('showing frame ' + id);
    switch(id) {

        //show frame 1
        case 1:

            resetBanner();

            // show logo
            setClass(logoExpedia, 0, "fadeIn");

            // show frame copy
            setClass(copy_frame01a, 0.5, "expandScroll");
            setClass(copy_frame01b, 1.1, "dropDownCopy");
            setClass(copy_frame01c, 1.5, "slideCopyRightAndIn");
            setClass(copy_frame01d, 1.9, "slideCopyLeftAndIn");

            holdFrame(2, 4.6);
            break;

        //show frame 2
        case 2:

            // hide prev copy
            setClass(copy_frame01a, 0, "fadeOut");
            setClass(copy_frame01b, 0, "fadeOut");
            setClass(copy_frame01c, 0, "fadeOut");
            setClass(copy_frame01d, 0, "fadeOut");

            // show frame copy
            setClass(copy_frame02, 0.5, "fadeIn");
          
            holdFrame(3, 3);
            break;

        //show frame 3
        case 3:

            // hide prev copy
            setClass(copy_frame02, 0, "fadeOut");
            
            // show frame copy
            setClass(copy_frame03, 0.5, "slideCopyDownAndIn");

            // pulse frame copy
            setClass(copy_frame03, 1.0, "pulseCopy");

            // show cta btn
            setClass(ctaBtn, 1.4, "fadeIn");

            // check if banner needs to loop
            window.setTimeout(checkForLooping, 2100);

            break;
    }
}

/**
 * function checks if banner should loop or show replay btn
 */
function checkForLooping()
{
    if(currentLoop < totalLoops) // loop baner
    {
        window.setTimeout(loopBanner, endFrameDelay*1000);
        currentLoop++;
    }
    else // show replay btn
    {   
        if(useReplayBtn)
        {
            btnReplay.style.display = "block";
        }
    }
}


function loopBanner()
{
    showFrame(1);
}


/**
 * function resets content on end frame to initial states
 */
function resetBanner()
{
    copy_frame03.className = "resetItemOpacity";
    ctaBtn.className = "resetItemOpacity";
    btnReplay.style.display = "none";
}
