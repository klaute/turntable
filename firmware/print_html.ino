
// The html and javascript code was compressed by https://htmlcompressor.com/compressor/
void printHTMLCtrlPanel(WiFiClient client, String ip)
{
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Turntable Control Panel</title>");
  client.println("</head>");
  client.println("<script src=\"https://code.jquery.com/jquery-3.3.1.min.js\"></script>");
  client.println("<script type=\"text/javascript\">var debug=false;var tt_statusUpdate_delay_ms=3000;var tt_timerId=setTimeout(tt_getStatus,10000);");
  client.println("function tt_getStatus(){getURLData(getBaseURL()+\"/STAT\");if(document.getElementById(\"hidden_data_div\").html){updateStatusView(\"Status: \"+document.getElementById(\"hidden_data_div\").html)}tt_timerId=setTimeout(tt_getStatus,tt_statusUpdate_delay_ms)}");
  client.println("function updateStatusView(a){if(debug){document.getElementById(\"systemStatus\").value=a+\"\\n\"+document.getElementById(\"systemStatus\").value}");
  client.println("else{document.getElementById(\"systemStatus\").value=a}}");
  client.println("function getBaseURL(){return document.getElementById(\"baseURL\").value}");
  client.println("function tt_setTurning(a){if(a==1){callURL(getBaseURL()+\"/EN\")}else{callURL(getBaseURL()+\"/DIS\")}}");
  client.println("function tt_setTurnDir(a){if(a==1){callURL(getBaseURL()+\"/DIR_H\")}else{callURL(getBaseURL()+\"/DIR_L\")}}");
  client.println("function tt_incDelayBetween(){callURL(getBaseURL()+\"/INC_DLY_BT\")}");
  client.println("function tt_decDelayBetween(){callURL(getBaseURL()+\"/DEC_DLY_BT\")}");
  client.println("function tt_incDelayAfter(){callURL(getBaseURL()+\"/INC_DLY_AF\")}");
  client.println("function tt_decDelayAfter(){callURL(getBaseURL()+\"/DEC_DLY_AF\")}");
  client.println("function tt_updateMS123State(){var c=document.getElementById(\"ms1\").checked?1:0;var b=document.getElementById(\"ms2\").checked?1:0;var a=document.getElementById(\"ms3\").checked?1:0;callURL(getBaseURL()+\"/MS_BM_\"+c+b+a)}");
  client.println("function callURL(a){$(\"#hiddenframe\").load(a,function(){if(debug){updateStatusView(\"call OK: \"+a)}})}");
  client.println("function getURLData(a){$.get(a,function(b){if(debug){updateStatusView(\"get OK: \"+a)}tmp_data=b;document.getElementById(\"hidden_data_div\").html=b.replace(/(\\r\\n\\t|\\n|\\r\\t)/gm,\"\")})}function setDebugMode(){debug=document.getElementById(\"debug\").checked};");
  client.println("function tt_saveCfg(){callURL(getBaseURL()+\"/SAVE_\"+document.getElementById(\"idx\").value);}function tt_loadCfg(){callURL(getBaseURL()+\"/LOAD_\"+document.getElementById(\"idx\").value);}");
  client.println("function tt_enableWebUpdate(){callURL(getBaseURL()+\"/WU\");window.open(\"http://"+ip+":8080/update\", \"_blank\");}");
  client.println("</script>");
  client.println("<body>");
  client.println("<br>");
  client.println("<input id=\"baseURL\" type=\"text\" value=\"http://" + ip + "/\">");
  client.println("<br>");
  client.println("<button id=\"enable\" onclick=\"tt_setTurning(1)\">enable</button>");
  client.println("<button id=\"disable\" onclick=\"tt_setTurning(0)\">disable</button>");
  client.println("<br>");
  client.println("<button id=\"save\" onclick=\"tt_saveCfg()\">save</button>");
  client.println("<button id=\"load\" onclick=\"tt_loadCfg()\">load</button>");
  client.println("<input id=\"idx\" value=\"0\">");
  client.println("<br>");
  client.println("<button id=\"left\" onclick=\"tt_setTurnDir(1)\">left</button>");
  client.println("<button id=\"right\" onclick=\"tt_setTurnDir(0)\">right</button>");
  client.println("<br>");
  client.println("<button id=\"inc_dly_bt\" onclick=\"tt_incDelayBetween()\">inc. delay between</button>");
  client.println("<button id=\"dec_dly_bt\" onclick=\"tt_decDelayBetween()\">dec. delay between</button>");
  client.println("<br>");
  client.println("<button id=\"inc_dly_af\" onclick=\"tt_incDelayAfter()\">inc. delay after</button>");
  client.println("<button id=\"dec_dly_af\" onclick=\"tt_decDelayAfter()\">dec. delay after</button>");
  client.println("<br>");
  client.println("<table>");
  client.println("<tr><td>MS1</td><td>MS2</td><td>MS3</td></tr>");
  client.println("<tr>");
  client.println("<td><input type=\"checkbox\" id=\"ms1\" onclick=\"tt_updateMS123State()\"></td>");
  client.println("<td><input type=\"checkbox\" id=\"ms2\" onclick=\"tt_updateMS123State()\"></td>");
  client.println("<td><input type=\"checkbox\" id=\"ms3\" onclick=\"tt_updateMS123State()\"></td>");
  client.println("</tr>");
  client.println("<br>");
  client.println("<textarea type=\"textfield\" id=\"systemStatus\" value=\"\" rows=\"4\" cols=\"50\"></textarea>");
  client.println("<br>");
  client.println("Debug mode: <input type=\"checkbox\" id=\"debug\" onclick=\"setDebugMode()\">");
  client.println("<br>");
  client.println("<button id=\"webUpdate\" onclick=\"tt_enableWebUpdate()\">WebUpdate</button>");
  client.println("<br>");
  client.println("<div style=\"display:none\" width=\"1px\" height=\"1px\" id=\"hidden_data_div\">&nbsp;</div>");
  client.println("<div style=\"display:none\" id=\"hiddenframe\"></div>");
  client.println("</body>");
  client.println("</html>");
}

