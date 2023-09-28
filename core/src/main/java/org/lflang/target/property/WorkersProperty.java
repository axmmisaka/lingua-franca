package org.lflang.target.property;

import java.util.List;
import org.lflang.MessageReporter;
import org.lflang.Target;
import org.lflang.TargetPropertyConfig;
import org.lflang.ast.ASTUtils;
import org.lflang.lf.Element;
import org.lflang.target.property.type.PrimitiveType;

public class WorkersProperty extends TargetPropertyConfig<Integer> {

  public WorkersProperty() {
    super(PrimitiveType.NON_NEGATIVE_INTEGER);
  }

  @Override
  public Integer initialValue() {
    return 0;
  }

  @Override
  protected Integer fromString(String value, MessageReporter err) {
    return Integer.parseInt(value); // FIXME: check for exception
  }

  @Override
  protected Integer fromAst(Element value, MessageReporter err) {
    return ASTUtils.toInteger(value);
  }

  @Override
  public List<Target> supportedTargets() {
    return List.of(Target.C, Target.CCPP, Target.Python, Target.CPP, Target.Rust);
  }

  @Override
  public Element toAstElement() {
    return ASTUtils.toElement(value);
  }
}
