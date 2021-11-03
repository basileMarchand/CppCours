// function to set cookie in web browser
let createCookie= function(cookieName, cookieValue, cookieExpireDays){
  let currentDate = new Date();
  currentDate.setTime(currentDate.getTime() + (cookieExpireDays*24*60*60*1000));
  let expires = "expires=" + currentDate.toGMTString();
  document.cookie = cookieName + "=" + cookieValue + ";" + expires + ";path=/";
  if(!document.cookie){
    alert("Unable to set cookie. Please allow all cookies site from cookie setting of your browser");
  }

}

// get cookie from the web browser
let getCookie= function(cookieName){
  let name = cookieName + "=";
  let decodedCookie = decodeURIComponent(document.cookie);
  let ca = decodedCookie.split(';');
  for(let i = 0; i < ca.length; i++) {
    let c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

function cookieConsent(cname, cvalue, cvalidity, popUpTitle, popUpBody, cb_yes, cb_no){

  // 1. Check if cookie already set 
  let need_popup = false; 
  let cookie_current = getCookie(cname);
  if( cookie_current == "" ){
    // no cookie set => popup
    need_popup = true; 
  }
  else if( cookie_current == "yes"){
    // Cookie set to yes => call the cb_yes callback 
    cb_yes();
  }
  else if( cookie_current == "no"){
    // Cookie set to no => call the cb_no callback 
    cb_no();
  }
  // 2. If not set install pop-up
  if( need_popup ){ 
    let popup = document.createElement("div");
    popup.id = "cookiePopup";

    let title = document.createElement("h4");
    title.innerHTML = popUpTitle;

    popup.appendChild(title);

    let content = document.createElement("p");
    content.innerHTML = popUpBody;
    popup.appendChild(content);

    let button = document.createElement("button");
    button.innerHTML = "Accepter";
    button.onclick = () => {
      createCookie(cname, "yes", cvalidity);
      popup.style.display = "none";
      cb_yes();
    }
    popup.appendChild(button);

    let reject = document.createElement("a");
    reject.style = "font-size: x-small; z-index: 10; cursor: pointer;";
    reject.innerHTML = "Continuer sans accepter";
    reject.onclick = ()=>{
      createCookie(cname, "no", cvalidity);
      popup.style.display = "none";
      cb_no();
    }
    popup.appendChild(reject);
    document.body.appendChild(popup);
  }
}


