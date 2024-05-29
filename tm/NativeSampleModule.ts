import {TurboModule, TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  readonly reverseString: (input: string) => string;

  readonly addNumbers: (a: number, b: number) => number;
}

export default TurboModuleRegistry.getEnforcing<Spec>(
  'NativeSampleModule',
);