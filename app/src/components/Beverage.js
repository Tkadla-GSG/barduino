import React, { Component } from 'react';
import { connect } from 'react-redux'
import { brewBeverage } from '../actions/beverage';

class Beverage extends Component {
    handleClick = () => this.props.onClick();

    render() {
        return (
            <div onClick={this.handleClick}>
                {'beverage '}{this.props.id}
            </div>
        );
    }
}

export default connect(
    undefined,
    (dispatch,  {id }) => ({
        onClick: () => dispatch(brewBeverage(id)),
    })
)(Beverage);
