import * as React from 'react';
import {BuylistTable} from './buylistTable/BuylistTable';

export const Buylist = () => {
  return (
    <div>
      <h1>Purplemana Buylist</h1>
      <div style={{height: 500, width: '100%'}}>
        <BuylistTable />
      </div>
    </div>
  );
};
