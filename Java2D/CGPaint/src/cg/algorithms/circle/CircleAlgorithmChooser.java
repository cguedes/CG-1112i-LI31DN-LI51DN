package cg.algorithms.circle;

import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;


public final class CircleAlgorithmChooser {

	private static Dictionary<String, ICircleAlgorithm> algorithms = new Hashtable<String, ICircleAlgorithm>();
	
	static {
		algorithms.put("MidPoint", new MidPointCircleAlgorithm());
		algorithms.put("CircleFill", new CircleFillAlgorithm());
	}
	
	public static Enumeration<String> getAvailableAlgorithms() {
		return algorithms.keys();
	}
	
	public static ICircleAlgorithm getAlgorithm(String algName) {
		return algorithms.get(algName);
	}
	
	public static ICircleAlgorithm getDefaultAlgorithm() {
		return algorithms.get(algorithms.keys().nextElement());
	}
	
	
	
}
