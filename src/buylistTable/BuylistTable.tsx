import * as React from 'react';
import {DataGrid, GridColumns, GridRowsProp} from '@mui/x-data-grid';
import {FunctionComponent} from 'react';

const columns: GridColumns = [
  {field: 'cardName', headerName: 'Card Name', width: 200},
  {field: 'set', headerName: 'Edition', width: 150},
  {field: 'prices', headerName: 'Buy Price (LP)', width: 200, align: 'right', headerAlign: 'right'},
];
const rows: GridRowsProp = [
  {id: 1, cardName: 'Hypnotic Specter', set: 'Alpha', prices: '$843.44'},
  {id: 2, cardName: 'Volcanic Island', set: 'Unlimited', prices: '$1023.55'},
  {id: 3, cardName: 'Sedge Troll', set: 'Unlimited', prices: '$43.25'},
  {id: 4, cardName: 'Howling Mine', set: 'Beta', prices: '$432.43'},
  {id: 5, cardName: 'Strip Mine (no horizon)', set: 'Antiquities', prices: '$55.25'},
];

export const BuylistTable: FunctionComponent = () => {
  return (
    <DataGrid columns={columns} rows={rows} />
  );
};
