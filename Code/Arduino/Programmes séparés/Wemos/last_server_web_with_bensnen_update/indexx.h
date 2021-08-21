const char index_html_2[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>

    <style>
        body { text-align: center; font-family: \"Trebuchet MS\", Arial;}
        table { border-collapse: collapse; width:35%; margin-left:auto; margin-right:auto; }
        th { padding: 14px; background-color: #02ffff; color: rgb(0, 0, 0); }
        tr { border: 1px solid rgb(0, 0, 0); padding: 10px; }
        tr:hover { background-color: #000; color: aliceblue;}
        td { border: none; padding: 12px; }
    </style>
   
    <title>HTML page of web server</title>
</head>






<body>
    <h1>arduino weather station wemos D1 </h1>


    <table>
        <tr><th>MEASUREMENT</th><th>VALUE</th></tr>
        <tr><td>water lavel</td><td><span id="whater_lavel">%WHATER_LAVEL%</span>%</td></tr>
        <tr><td>Temp. Celsius</td><td><span id="temperature">%TEMPERATURE% </span> C</td></tr>
        <tr><td>Temp. Fahrenheit</td><td><span id="temperatureF">%TEMPERATUREF%</span> F</td></tr>
        <tr><td>Pressure</td><td><span id="pressure">%PRESSURE%</span>hPa</td></tr>
        <tr><td>Humidity</td><td><span id="humidity">%HUMIDITY%</span>%</td></tr>
        <tr><td>Point de rosee</td><td><span id="point_de_rose">%POINTDEROSEE%</span></td></tr>
    </table>



    <p>
      <i class="far fa-clock" style="font-size:1.0rem;color:#e3a8c7;"></i>
      <span style="font-size:1.0rem;">Time :  </span>
      <span id="time" style="font-size:1.0rem;"> | </span>
      <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#f7dc68";></i>
      <span style="font-size:1.0rem;">   ||  Date :   </span>
      <span id="date" style="font-size:1.0rem;"></span>
    </P>
  
  
</body>





<script>

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("whater_lavel").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/whater_lavel", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperature").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/temperature", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperatureF").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/temperatureF", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("pressure").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/pressure", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("humidity").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/humidity", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("point_de_rose").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/point_de_rose", true);
    xhttp.send();
    }, 1000 ) ;

    setInterval(function ( ) {
        var t = new Date();
        document.getElementById("time").innerHTML = t.toLocaleTimeString();
        var d = new Date();
        const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"];
        const monthNames = ["January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"];
        document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
      },1000);

</script>





</html>)=====";
