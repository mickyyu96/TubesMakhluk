jdepend_swing:
	java -cp .;jdepend-2.9.1.jar; jdepend.swingui.JDepend .\\
	
jdepend_text:
	java -cp .;jdepend-2.9.1.jar; jdepend.textui.JDepend -file text.txt .\\
	
jdepend_xml:
	java -cp .;jdepend-2.9.1.jar; jdepend.xmlui.JDepend -file xml.txt .\\