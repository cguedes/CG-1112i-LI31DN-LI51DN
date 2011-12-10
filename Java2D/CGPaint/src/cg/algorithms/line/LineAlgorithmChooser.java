package cg.algorithms.line;

import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;


public final class LineAlgorithmChooser {

	private static Dictionary<String, IScanLineAlgorithm> algorithms = new Hashtable<String, IScanLineAlgorithm>();
	
	static {		
		algorithms.put("Basic Scan", new BasicScanLineAlgorithm());
		algorithms.put("Bresenham", new BresenhamLineAlgorithm());
		//algorithms.put("MidPoint", new MidPointLineAlgorithm());
	}
	
	public static Enumeration<String> getAvailableAlgorithms() {
		return algorithms.keys();
	}
	
	public static IScanLineAlgorithm getAlgorithm(String algName) {
		return algorithms.get(algName);
	}
	
	public static IScanLineAlgorithm getDefaultAlgorithm() {
		return algorithms.get(algorithms.keys().nextElement());
	}
	
	
	
}
